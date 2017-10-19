enum log_levels{ERROR, INFO, DEBUG};
// change this to change the log level
const int LOG_LEVEL = DEBUG;

void log(String level, String separator, String message)
{
    Serial.println("[" + level + "]" + separator + message);
}

void tabbedLog(String level, String message)
{
    log(level, "\t", message);
}

void printHeader(String message)
{
    log("header", "", message);
}

void error(String message)
{
    if (LOG_LEVEL >= ERROR)
    {
        tabbedLog("error", message);
    }
}

void info(String message)
{   
    if (LOG_LEVEL >= INFO)
    {
        tabbedLog("info", message);    
    }
}

void debug(String message)
{
    if (LOG_LEVEL >= DEBUG)
    {
        tabbedLog("debug", message);
    }
}
