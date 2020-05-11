/**
 * @file street.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice metod třídy reprezentující ulici
 */

#ifndef STREET_HPP
#define STREET_HPP

#include <QString>
#include <QHash>
#include <QPoint>

/**
 * @brief Třída reprezentující ulici
 */
class Street
{
private:
    /**
     * @brief Unikátní řetězec identifikující ulici
     */
    QString id;

    /**
     * @brief Název ulice
     */
    QString name;

    /**
     * @brief Počáteční bod ulice na mapě
     */
    QPoint begin;

    /**
     * @brief Koncový bod ulice na mapě
     */
    QPoint end;

    /**
     * @brief Pozice zastávky v % (0.0-1.0) od začátku ulice
     *
     * Pokud je hodnota < 0, na ulici není zastávka
     */
    float stopPos;

    /**
     * @brief Provoz v ulici.
     *
     * Sekundy zpoždění, které vozidlo nabere projetím ulice
     */
    int traffic;

public:
    /**
     * @brief Inicializuje ulici s výchozími hodnotami
     *
     * Nedoporučuje se používat. Nelze poté nastavit ID ulice!
     */
    Street();

    /**
     * @brief Inicializace ulice
     * @param id Unikátní ID ulice
     */
    Street(QString id);

    /**
     * @brief Inicializace ulice
     * @param id Unikátní ID ulice
     * @param name Název ulice
     * @param beginPos Počateční bod ulice
     * @param endPos Koncový bod ulice
     * @param stopPos Pozice zastávky na ulici (v % od 0 do 1, -1 pokud nemá zastávku)
     */
    Street(QString id, QString name, QPoint beginPos, QPoint endPos, float stopPos);

    /**
     * @brief Porovnání dvou ulic
     *
     * Ulice se porovnávají svým ID
     *
     * @param rhs Druhá ulice k porovnání
     * @return Jedná se o identickou ulici
     */
    bool operator==(const Street& rhs) const;

    /**
     * @brief Porovnání ulice s ID ulice
     * @param rhs řetezec s ID ulice
     * @return Ulice má toto ID
     */
    bool operator==(const QString& rhs) const;

    /**
     * @brief Získat ID ulice
     * @return ID ulice
     */
    QString getID() const;

    /**
     * @brief Získat název ulice
     * @return Název ulice
     */
    QString getName() const;

    /**
     * @brief Nastavit název ulice
     * @param value Nový nízev ulice
     */
    void setName(const QString &value);

    /**
     * @brief Získat počíteční bod ulice
     * @return Počáteční bod ulice
     */
    QPoint getBegin() const;

    /**
     * @brief Změnit počáteční bod ulice
     * @param Nový počáteční bod ulice
     */
    void setBegin(const QPoint &value);

    /**
     * @brief Získat koncový bod ulice
     * @return Koncový bod ulice
     */
    QPoint getEnd() const;

    /**
     * @brief Změnit koncový bod ulice
     * @param value Nový koncový bod ulice
     */
    void setEnd(const QPoint &value);

    /**
     * @brief Získat pozici zastávky na ulici
     * Hodnota vrací -1, pokud na ulici není zastávka
     *
     * @return Pozice zastávky jako procentuální hodnota od počátku ulice
     */
    float getStopPos() const;

    /**
     * @brief setStopPos Změnit pozici zastávky na ulici
     * @param value Nová procentuální pozice zastávky od počátku. -1 pokud má být zastávka odstraněna.
     */
    void setStopPos(float value);

    /**
     * @brief Získat informace o provozu (zpoždění)
     * @return Zpoždení v sec, které vozidlo při průjezdu ulicí nabere
     */
    int getTraffic() const;

    /**
     * @brief Nastavit novou hodnotu provozu
     * @param value Nové zpoždení v sec
     */
    void setTraffic(int value);
};

/**
 * @brief Seznam ulic, kde klíč je ID ulice a hodnota je instance ulice
 */
class StreetList : public QHash<QString, Street*>{

};

#endif // STREET_HPP
