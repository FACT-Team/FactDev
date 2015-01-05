#ifndef LOG_H
#define LOG_H
#include <QFile>
typedef enum {INFO, ERREUR, WARNING }TypeLog;

/**
 * @brief The Log class for Simple management of log.
 */
class Log
{
public:
    static Log &instance(TypeLog type=INFO);
    ~Log();
    void write(const QString text);
    Log();

    /**
     * @brief operator << for log writing
     * @param logger Instance of Logger
     * @param text Text to write
     * @return New logger.
     */
    friend Log &operator << (Log &logger, const QString& text) {
        logger.write(text);

        return logger;
    }
private:
    static Log* _instance;
    static TypeLog _type;

    QFile* _file;
    QString head();
    QString typeLog2String(TypeLog type);
};

#endif // LOG_H
