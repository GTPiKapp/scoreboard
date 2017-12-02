void vprintfmt(void (*putch)(char*), const char *fmt, va_list ap);



/*
 * Print a number (base <= 16) in reverse order,
 * using specified putch function and associated pointer putdat.
 */
static void
printnum(void (*putch)(char*), unsigned long long num,
          unsigned base, int width, int padc)
{
  // first recursively print all preceding (more significant) digits
  if (num >= base)
    printnum(putch, num / base, base, width - 1, padc);
  else {
    // print any needed pad characters before first digit
    while (--width > 0)
      putch(padc);
  }

  // then print this (the least significant) digit
  putch("0123456789abcdef"[num % base]);
}

// Get an unsigned int of various possible sizes from a varargs list,
// depending on the lflag parameter.
static unsigned long long
getuint(va_list *ap, int lflag)
{
  if (lflag >= 2)
    return va_arg(*ap, unsigned long long);
  else if (lflag)
    return va_arg(*ap, unsigned long);
  else
    return va_arg(*ap, unsigned int);
}

// Same as getuint but signed - can't use getuint
// because of sign extension
static long long
getint(va_list *ap, int lflag)
{
  if (lflag >= 2)
    return va_arg(*ap, long long);
  else if (lflag)
    return va_arg(*ap, long);
  else
    return va_arg(*ap, int);
}

void
putch(const char *ch)
{
  Serial.print(ch);
}

int
printf(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
}

void
strprintf(String fmtStr, ...)
{
  va_list ap;
  const char fmt[fmtStr.length()];

  fmtStr.toCharArray(fmt, fmtStr.length());

  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
}

int
lprintf(const char *fmt, va_list ap)
{
  vprintf(fmt, ap);
  putch("\n");
}

int
vprintf(const char *fmt, va_list ap)
{
  vprintfmt(putch, fmt, ap);
}

void
vprintfmt(void (*putch)(char*), const char *fmt, va_list ap)
{
  register const char *p;
  register int ch, err;
  unsigned long long num;
  int base, lflag, width, precision, altflag;
  char padc;

  while (1) {
    while ((ch = *(unsigned char*)fmt++) != '%') {
      if (ch == '\0')
        return;
      putch(ch);
    }

    // Process a %-escape sequence
    padc = ' ';
    width = -1;
    precision = -1;
    lflag = 0;
    altflag = 0;
reswitch:
    switch (ch = *(unsigned char*)fmt++) {

    // flag to pad on the right
    case '-':
      padc = '-';
      goto reswitch;

    // flag to pad with 0's instead of spaces
    case '0':
      padc = '0';
      goto reswitch;

    // width field
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      for (precision = 0;; ++fmt) {
        precision = precision * 10 + ch - '0';
        ch = *fmt;
        if (ch < '0' || ch > '9')
          break;
      }
      goto process_precision;

    case '*':
      precision = va_arg(ap, int);
      goto process_precision;

    case '.':
      if (width < 0)
        width = 0;
      goto reswitch;

    case '#':
      altflag = 1;
      goto reswitch;

process_precision:
      if (width < 0)
        width = precision, precision = -1;
      goto reswitch;

    // long flag (doubled for long long)
    case 'l':
      lflag++;
      goto reswitch;

    // character
    case 'c':
      putch(va_arg(ap, int));
      break;

    // // error message
    // case 'e':
    //   err = va_arg(ap, int);
    //   if (err < 0)
    //     err = -err;
    //   if (err >= MAXERROR || (p = error_string[err]) == NULL)
    //     printfmt(putch, putdat, "error %d", err);
    //   else
    //     printfmt(putch, putdat, "%s", p);
    //   break;

    // string
    case 's':
      if ((p = va_arg(ap, char *)) == NULL)
        p = "(null)";
      if (width > 0 && padc != '-')
        for (width -= strnlen(p, precision); width > 0; width--)
          putch(padc);
      for (; (ch = *p++) != '\0' && (precision < 0 || --precision >= 0); width--)
        if (altflag && (ch < ' ' || ch > '~'))
          putch('?');
        else
          putch(ch);
      for (; width > 0; width--)
        putch(' ');
      break;

    // (signed) decimal
    case 'd':
      num = getint(&ap, lflag);
      if ((long long)num < 0) {
        putch('-');
        num = -(long long)num;
      }
      base = 10;
      goto number;

    // unsigned decimal
    case 'u':
      num = getuint(&ap, lflag);
      base = 10;
      goto number;

    // (unsigned) octal
    case 'o':
      num = getuint(&ap, lflag);
      base = 8;
      goto number;

    // pointer
    case 'p':
      putch('0');
      putch('x');
      num = (unsigned long long)
            (uintptr_t)va_arg(ap, void *);
      base = 16;
      goto number;

    // (unsigned) hexadecimal
    case 'x':
      num = getuint(&ap, lflag);
      base = 16;
number:
      printnum(putch, num, base, width, padc);
      break;

    // escaped '%' character
    case '%':
      putch(ch);
      break;

    // unrecognized escape sequence - just print it literally
    default:
      putch('%');
      for (fmt--; fmt[-1] != '%'; fmt--)
        /* do nothing */;
      break;
    }
  }
}


