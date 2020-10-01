#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QFileDialog>
#include <QMenu>

#include <paintscene.h>



QT_BEGIN_NAMESPACE
namespace Ui {
class Paint;
}
QT_END_NAMESPACE

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = 0);
    ~Paint();


private:
    Ui::Paint *ui;
    QTimer *timer;
    void mousePressEvent(QMouseEvent * event);
    /* Определяем таймер для подготовки актуальных размеров
                             * графической сцены
                         * */
    paintScene *scene;  // Объявляем кастомную графическую сцену

    QMenu *menu = new QMenu("Menu",this);
    QAction *action = new QAction ("Eraser");


private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
    void on_save_clicked();
    void on_open_clicked();
    void on_clear_clicked();
    void on_red_clicked();
    void on_blue_clicked();
    void on_green_clicked();
};

#endif // PAINT_H
