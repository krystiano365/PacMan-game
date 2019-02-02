#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "consts.h"
#include "pacman.h"
#include <QWidget>
#include <QKeyEvent>
#include <memory>
#include <QTimer>

class MyWidget : public QWidget
{
	Q_OBJECT
private:
	QTimer *timer;
	int frameCounter = 0;
	std::vector<QRect> walls_horizontal;
	std::vector<QRect> walls_vertical;
	std::vector<QRect> walls_1;
	std::vector<QRect> walls_2;
	std::vector<QRect> walls_3;
	std::vector<QRect> walls_4;
	std::vector<std::shared_ptr<QRect>> allWalls;
	std::list<QRect> points;
	std::list<QPoint> bigPoints;
//	std::list<Ghost> ghosts;
	Pacman pacman;
	std::vector<std::string> mapArray;
	void startGame();
	void loadMap();
	void distributeMapObjects();
	void drawWalls(QPainter &painter, std::vector<QRect> &wallType, QPixmap image);
	void drawWalls2(QPainter &painter, std::vector<std::shared_ptr<QRect>> &wallType, QPixmap image);
	void drawPoints(QPainter &painter);
	void drawPacman(QPainter &painter);
	void handleSmallPointCollision();
public:
	explicit MyWidget(QWidget *parent = nullptr);
	~MyWidget();

	void paintEvent(QPaintEvent *);
	void keyPressEvent(QKeyEvent *);
public slots:
	void updateScreen();
};

#endif // MYWIDGET_H
