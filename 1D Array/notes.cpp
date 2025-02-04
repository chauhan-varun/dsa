#include<iostream>
using namespace std;

int main()
{
	int x,n1, n2, n5, n10, n20, n50, n100, n200, n500, n2000;
	cin>>x;
	n1=n2=n5=n10=n20=n50=n100=n200=n500=n2000=0;
	switch(x>=2000){
		case 1:
		n2000=x/2000;
		x-=n2000*2000;
	}
	switch( x>=500){
		case 1:
		n500=x/500;
		x-=n500*500;
	}
	switch(x>=200){
		case 1:
		n200=x/200;
		x-=n200*200;
	}
	switch(x>=100){
		case 1:
		n100=x/100;
		x-=n100*100;
	}
	switch(x>=50){
		case 1:
		n50=x/50;
		x-=n50*50;
	}
	switch(x>=20){
		case 1:
		n20=x/20;
		x-=n20*20;
	}
	switch(x>=10){
		case 1:
		n10=x/10;
		x-=n10*10;
	}
	switch(x>=5){
		case 1:
		n5=x/5;
		x-=n5*5;
	}
	switch(x>=2){
		case 1:
		n2=x/2;
		x-=n2*2;
	}
	switch(x>=1){
		case 1:
		n1=x/1;
		x-=n1*1;
	}
	cout<<"notes of 2000: "<<n2000<<endl;
	cout<<"notes of 500 : "<<n500<<endl;
	cout<<"notes of 200: "<<n200<<endl;
	cout<<"notes of 100: "<<n100<<endl;
	cout<<"notes of 50: "<<n50<<endl;
	cout<<"notes of 20: "<<n20<<endl;
	cout<<"notes of 10: "<<n10<<endl;
	cout<<"notes of 5: "<<n5<<endl;
	cout<<"notes of 2: "<<n2<<endl;
	cout<<"notes of 1: "<<n1<<endl;
	
    return 0;
}