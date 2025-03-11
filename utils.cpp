#include "utils.h"

#include <QRegularExpression>

bool validate_rxr(QString r)
{
    static QRegularExpression re("^(rxr)?\\s*\\d\\d\\d\\d\\d\\d\\d$", QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch m = re.match(r.trimmed().toUpper(), 0);
    return m.hasMatch();
}

QString clean_rxr(QString r)
{
    return r.trimmed().toUpper();
}


QString clean_mrn(QString r)
{
    static QRegularExpression re("\\d\\d\\d\\d\\d\\d\\d", QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch m = re.match(r.trimmed().toUpper(), 0);
    if(m.hasMatch()){
        return "RXR" + m.captured(0);
    }

    return "";
}
