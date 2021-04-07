#include "Cvijet.h"
#include<SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Suncokret(sf::CircleShape& cvijet, int x,int y);
void Stabiljka(sf::RectangleShape& stabiljka, int x, int y);
void List(sf::ConvexShape& list, int x,int y);
void Sunce(sf::CircleShape& sunce,int y);
void Tlo(sf::RectangleShape& tlo);
void Zraka(sf::RectangleShape& zraka,float x_kor,float y_kor,int rotation, int y);


void Cvijet::draw(int &y)
{
	int x = 0;
	int rotation[8]{ 0,90,45,180,135 ,270,225,315};
	float x_kor[8]{ 125,60,105,-5,10,60,15,105};
	float y_kor[8]{ 90,155,135,90,135,25,40,40 };
	sf::CircleShape cvijet[3];
	sf::RectangleShape stabiljka[3];
	sf::ConvexShape list[3];
	sf::CircleShape sunce;
	sf::RectangleShape tlo;
	sf::RectangleShape zraka[8];

	Tlo(tlo);
	window->draw(tlo);
	
	Sunce(sunce, y);
	window->draw(sunce);
	
	for (int i = 0; i < 8; i++)
	{
		Zraka(zraka[i], x_kor[i], y_kor[i], rotation[i],y);
		window->draw(zraka[i]);
	}
	
	for (int i = 0; i < 3; i++)
	{
		Suncokret(cvijet[i], x, y);
		Stabiljka(stabiljka[i], x, y);
		List(list[i], x, y);
		window->draw(cvijet[i]);
		window->draw(stabiljka[i]);
		window->draw(list[i]);
		x += 275;
	}
	x = 0;
}

void Suncokret(sf::CircleShape &cvijet, int x,int y)
{
	cvijet.setRadius(70.f);
	cvijet.setPosition(50+x + 0.08 * y, 300 + 0.02 * y);
	cvijet.setFillColor(sf::Color(165, 42, 42));
	cvijet.setOutlineThickness(28.f);
	cvijet.setOutlineColor(sf::Color(255, 255, 0));
}

void Stabiljka(sf::RectangleShape &stabiljka,int x, int y)
{
	stabiljka.setSize(sf::Vector2f(150.f, 10.f));
	stabiljka.setPosition(125+x, 468);
	stabiljka.setFillColor(sf::Color(0, 255, 0));
	stabiljka.setOutlineColor(sf::Color(0, 255, 0));
	stabiljka.setRotation(90+0.04*y);
}

void List(sf::ConvexShape &list,int x, int y)
{
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(125.f+x-0.1 *y, 570.f + 0.05 * y));
	list.setPoint(1, sf::Vector2f(135.f + x - 0.08 * y,490.f + 0.07 * y));
	list.setPoint(2, sf::Vector2f(290.f + x - 0.08 * y,405.f + 0.06 * y));
	list.setPoint(3, sf::Vector2f(215.f + x - 0.08 * y,540.f + 0.06 * y));
	list.setFillColor(sf::Color(0, 255, 0));
}

void Sunce(sf::CircleShape& sunce,int y)
{
	sunce.setRadius(60.f);
	sunce.setPosition(0.f+y, 30.f);
	sunce.setFillColor(sf::Color(255, 201, 34));
}

void Tlo(sf::RectangleShape& tlo)
{
	tlo.setSize(sf::Vector2f(800.f, 580.f));
	tlo.setPosition(0.f, 0.f);
	tlo.setOutlineThickness(20.f);
	tlo.setFillColor(sf::Color(135, 206, 250));
	tlo.setOutlineColor(sf::Color(0, 255, 0));
}

void Zraka(sf::RectangleShape& zraka, float x_kor, float y_kor, int rotation, int y)
{
	zraka.setSize(sf::Vector2f(0+0.1*y, 2.f));
	zraka.setPosition(x_kor+y, y_kor);
	zraka.setFillColor(sf::Color(255, 255, 0));
	zraka.setRotation(rotation);
}
