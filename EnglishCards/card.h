#ifndef ENGLISHCARDS_CARD_H
#define ENGLISHCARDS_CARD_H

#include <QString>
#include <QList>

namespace EnglishCards {

class Card
{
public:
    Card();

    void next();
    void prev();

    QString english() const;
    QString russian() const;
    QString picture() const;
    QString englishAudio() const;
    QString russianAudio() const;
    QString video() const;

private:

    struct Path
    {
        QString engText;
        QString rusText;
        QString picture;
        QString engAudio;
        QString rusAudio;
        QString video;
    };

    void init();

    QList<Path> content;
    int current{};
};

}


#endif // ENGLISHCARDS_CARD_H
