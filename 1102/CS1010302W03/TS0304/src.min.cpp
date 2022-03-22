#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;string s="Out of range.";int a,b;char c[100000][10000];void L(int d,int e,int f,int g);void S(int w,int x,int y);void T(int w,int x,int y,string h);void i(){for(int i=0;i<b;++i){for(int j=0;j<a;++j){cout<<c[j][i];}cout<<"\n";}}void S(int w,int x,int y){if((x+w)>a||(y+w)>b){cout<<s<<"\n";return;}for(int i=0;i<w;++i){for(int j=0;j<w;++j){c[x+i][y+j]='X';}}i();}void T(int w,int x,int y,string o){int n;w-=1;if(o=="LU"){if((x-w)<0||(y-w)<0){cout<<s<<"\n";return;}for(int j=0;j<=w;++j){for(int i=0;i<=w-j;++i){c[x-j][y-i]='X';}}}else if(o=="RU"){if((x+w)>a||(y-w)<0){cout<<s<<"\n";}}