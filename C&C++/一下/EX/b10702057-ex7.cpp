// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex7.cpp
// Compiler�GDev C++
// Date�G2019/04/18
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Point{
	private:
		double x, y;  //���ܼ� 
	public:
		Point(double _x = 0, double _y = 0){ //���ܼ� 
			setPoint(_x, _y);
		}
		void setPoint(double _x, double _y){
			x = _x;
			y = _y;
		}
		double getX(){ return x;}
		double getY(){ return y;}
		
		double line(Point g, Point k) {
			return sqrt(pow(g.x - k.x, 2) + pow(g.y - k.y, 2));
		}
		
		void Point_2(Point a[], int n){ // �p������I�O�̵u�Z�� 
			double linemin;
			Point minA, minB;
			for ( int i = 0; i < n; i++){
				for ( int l = 0; l < n; l++){
					if ( i == l){
					}
					else {
						if (i == 0 && l == 1){
							linemin = line(a[i], a[l]);
							minA = a[i];
							minB = a[l];
						}
						else{
							double lineK = line(a[i], a[l]);
							if ( linemin > lineK){
								linemin = lineK;
								minA = a[i];
								minB = a[l];
							}
						}
					}
				}
			}
			printf("(%.2lf, %.2lf) is nearest to (%.2lf, %.2lf) and the distance is %.10lf.\n", minA.x, minA.y, minB.x, minB.y, linemin);
		}
};

void t(Point a[],int n, double k[]){
	for (int i = 0, p = 0; p < n; i++,i++,p++){
		a[p].setPoint(k[i], k[i+1]);
	}
}



int main(void){  //�D�{���I�s�Ӳ[�� 
	Point a[100];
	double k[200];
	int n;
	cout << "Enter n:";
	cin >> n;
	for (int i = 0; i < 2 * n; i++){
		cin >> k[i];
	}
	t(a, n, k);
	a[100].Point_2(a, n);
}
