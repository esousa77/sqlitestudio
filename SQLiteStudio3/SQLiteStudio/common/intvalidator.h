#ifndef INTVALIDATOR_H
#define INTVALIDATOR_H

#include <QIntValidator>
#include <QString>

class IntValidator : public QIntValidator
{
    Q_OBJECT

    public:
        explicit IntValidator(QObject *parent = 0);
        explicit IntValidator(int min, int max, QObject *parent = 0);

        void fixup(QString& input) const;

        int getDefaultValue() const;
        void setDefaultValue(int value);

    private:
        int defaultValue = 0;
};

#endif // INTVALIDATOR_H
