#include "card.h"
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace
{
    namespace dirs
    {
        const QString program   = QDir::current().absolutePath();

        const QString data      = program   + "/english";
        const QString text      = data      + "/text";
        const QString images    = data      + "/images";
        const QString english   = data      + "/english";
        const QString russian   = data      + "/russian";
        const QString video     = data      + "/video";
    }
}

EnglishCards::Card::Card()
{
    init();
}

void EnglishCards::Card::next()
{
    if (current >= content.size() - 1)
        return;

    ++current;
}

void EnglishCards::Card::prev()
{
    if (current <= 0)
        return;

    --current;
}

QString EnglishCards::Card::english() const
{
    return content[current].engText;
}

QString EnglishCards::Card::russian() const
{
    return content[current].rusText;
}

QString EnglishCards::Card::picture() const
{
    return content[current].picture;
}

QString EnglishCards::Card::englishAudio() const
{
    return content[current].engAudio;
}

QString EnglishCards::Card::russianAudio() const
{
    return content[current].rusAudio;
}

QString EnglishCards::Card::video() const
{
    return content[current].video;
}

void EnglishCards::Card::init()
{
    QStringList textFiles = QDir(dirs::text).entryList(QStringList("*.txt"), QDir::Files);

    for (const auto & x : textFiles)
    {
        QString filename =  dirs::text + '/' + x;
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QTextStream stream(&file);
        QString englishText = stream.readLine();
        QString russianText = stream.readLine();

        QString imageFile = dirs::images + '/' + englishText + ".jpg";
        QString englishAudioFile = dirs::english + '/' + englishText + ".mp3";
        QString russianAudioFile = dirs::russian + '/' + englishText + ".mp3";
        QString videoFile = dirs::video + '/' + englishText + ".mp4";

        if (!QFile(imageFile).exists())
            imageFile = "";

        if (!QFile(englishAudioFile).exists())
            englishAudioFile = "";

        if (!QFile(russianAudioFile).exists())
            russianAudioFile = "";

        if (!QFile(videoFile).exists())
            videoFile = "";

        Path path{englishText, russianText, imageFile, englishAudioFile, russianAudioFile, videoFile};
        content.push_back(path);
        file.close();
    }
}
