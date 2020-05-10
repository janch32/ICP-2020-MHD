#ifndef BUSDETAIL_HPP
#define BUSDETAIL_HPP

#include <QWidget>

namespace Ui {
class BusDetail;
}

class BusDetail : public QWidget
{
    Q_OBJECT

public:
    explicit BusDetail(QWidget *parent = nullptr);
    ~BusDetail();

private:
    Ui::BusDetail *ui;
};

#endif // BUSDETAIL_HPP
