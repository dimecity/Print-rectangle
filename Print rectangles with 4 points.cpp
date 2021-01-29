#include <iostream>
using namespace std;

class point{
    int x,y;

  public:
    point( )
    { x=y=0;}
    point(int xvalue, int yvalue);
    
    void setpoint(int new_x, int new_y);
    void setX(int new_x);
    void setY(int new_y);
    int getX( ) const;
    int getY( ) const;
    
    friend ostream & operator<<(ostream & os, const point& p);
};

point::point(int xvalue, int yvalue)
{
  setpoint(xvalue,yvalue);
}

void point::setX(int new_x)
{
        x = new_x;
}

void point::setY(int new_y)
{
  y = new_y;
}

int point::getX( ) const
{
  return x;
}

int point::getY( ) const
{
  return y;
}

void point::setpoint(int new_x, int new_y)
{
  x = new_x;
  y = new_y;
}

ostream & operator<<(ostream & os, const point& p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

class rectangle{
  public:
    point v1;
    point v2;
    point v3;
    point v4;
    int wid;
	int len;
    rectangle( )
    {}
    rectangle(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4);
    rectangle(int px1, int py2, int wid, int len);
    rectangle(point p1, point p2);
    void setRectangle1( int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4);
    void setRectangle2(int px1, int py1, int wid, int len);
    void setRectangle3(int px1, int py1, int px2, int py2);
    point getVertex1( ) const;
    point getVertex2( ) const;
    point getVertex3( ) const;
    point getVertex4( ) const;
    void setVertex1(point p1);
    void setVertex2(point p2);
    void setVertex3(point p3);
    void setVertex4(point p4);
    virtual void print() { 
        cout << "Print rectangle class" << endl; 
    }     
    friend ostream & operator<<(ostream & os, const rectangle& t);
};

rectangle::rectangle(int px1, int py1, int wid, int len) 
{
	setRectangle2(px1, py1, wid, len);
}

rectangle::rectangle(point p1, point p2) 
{
	setRectangle3(p1.getX( ), p1.getY( ), p2.getX( ), p2.getY( ));
}

rectangle::rectangle(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4)
{
  setRectangle1(px1, py1, px2, py2, px3, py3, px4, py4);
}

void rectangle::setRectangle1( int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4)
{
  v1 = point(px1, py1);
  v2 = point(px2, py2);
  v3 = point(px3, py3);
  v4 = point(px4, py4);
}
 void rectangle::setRectangle2(int px1, int py1, int wid, int len)
{
 	v1 = point(px1, py1);
 	v2 = point(px1 + len, py1);
 	v3 = point(px1, py1 - wid);
 	v4 = point(px1 + len, py1 - wid);
}

void rectangle::setRectangle3(int px1, int py1, int px2, int py2)
{
	v1 = point(px1, py1); 
	v2 = point(px2, py1);
	v3 = point(px2, py2);
	v4 = point(px1, py2);
}
    
point rectangle::getVertex1( ) const
{
  return v1;
}

    
point rectangle::getVertex2( ) const
{
  return v2;
}

    
point rectangle::getVertex3( ) const
{
  return v3;
}

point rectangle::getVertex4( ) const
{
  return v4;
}

void rectangle::setVertex1(point p1)
{
  v1 = p1;
}
   
void rectangle::setVertex2(point p2)
{
  v2 = p2;
}

void rectangle::setVertex3(point p3)
{
  v3 = p3;
}

void rectangle::setVertex4(point p4)
{
  v4 = p4;
}

ostream & operator<<(ostream & os, const rectangle& t)
{
  os << t.v1 << " " << t.v2 << " " << t.v3 << " " << t.v4;
  return os;
}

class square : public rectangle {	
		int length;
	public:
		square() {}
		square(int x, int y, int length);
		void setSquare (int x, int y, int length);
		void print() { 
        	cout << "Print square class" << endl; 
    	}
		~square() {}	
};

square::square(int x, int y, int length) {
	setSquare(x, y, length);
}

void square::setSquare(int x, int y, int length) {
	v1 = point(x, y);
	v2 = point(x + length, y);
	v3 = point(x + length, y + length);
	v4 = point(x, length);
}




int main( )
{
	rectangle a;
	square b(2, 2, 5);
	rectangle* x = &a;
	rectangle* y = &b;	
	x->print();
	y->print();	
    cout << b;
    return 0;
}


/*    
Name: Nguyen Truong
Date: 3/21
*/
