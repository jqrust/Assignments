//itp10705, Abdullah Enes Keskin,20142015
#include<iostream>
using namespace std;
#define max_x 50
#define max_y 50
char initializer(char (&array)[max_x][max_y] ,int w,int h){
	for(int i=0; i<h;i++)
		for(int j=0;j<w;j++)
			array[j][i]='.';
		
}
void display(const char (&grid)[max_x][max_y],int w ,int h,int g){
	cout<<"Generation "<<g<<":"<<endl;
		cout<<"+";
		for(int b=0; b<w*2+1;b++)
			cout<<"-";
		cout<<"+"<<endl;
		for(int j=0; j<h;j++){
			cout<<"| ";
			for(int k=0;k<w;k++){
				cout<<grid[k][j]<<" ";
			}
			cout<<"|";
			cout<<endl;
		}
		cout<<"+";
		for(int b=0; b<w*2+1;b++)
			cout<<"-";
		cout<<"+"<<endl;
	cout<<endl;
}

void obtain(char (&grid)[max_x][max_y] ,int w,int h,int& gen){
	int tempx[100],tempy[100],input=0,x,y;
	bool used=0; 
	do{
		used=0; 
		cout<<"Please enter the location of a live cell (enter -1 when no more live cell): ";
		cin>>x ;
		if(x ==-1) break;
		cin >> y;
		if(x<0||x>w-1){
			cout<<"The x-coordinate must be an integer in [0, "<<w-1<<"]."<<endl;
			continue;
		}
		if(y<0||y>w-1){
			cout<<"The y-coordinate must be an integer in [0, "<<h-1<<"]."<<endl;
			continue;
		}
		for(int t=0; t<input;t++){
			if(tempx[t]==x&&tempy[t]==y)
			used=1;
		}
		if(used){
			cout<<"You have already entered the location previously."<<endl;
			continue;
		}
		tempx[input]=x;
		tempy[input]=y;
		input++;
		grid[x][y] = '0';
	}while(x!=-1||y!=-1);
	cout<<"For how many generations does the simulation run? ";
	cin >>gen;
	while(gen<0){
		cout<<"Error: The number of generations must be a non-negative integer."<<endl;
		cout<<"For how many generations does the simulation run? ";
		cin >>gen;
	}
}
void neighbor_calculator(int (&n)[max_x][max_y],const char (&grid)[max_x][max_y],int w,int h){
	for(int i=0; i<h ;i++)
		for(int j=0; j<w;j++)
			n[j][i]=0;
	for(int i=0; i<h;i++)
		for(int j=0; j< w;j++){
			for(int k=i-1;k<=i+1;k++){
				if(k<0||k>=h) continue;
				for(int l=j-1;l<=j+1;l++){
					if(l<0||l>=w) continue;
					if(l==j&&k==i) continue;
					if(grid[l][k]=='0')
					n[j][i]++;
				}
			}
		}
}

void next_gen(char (&ngrid)[max_x][max_y],const char (&grid)[max_x][max_y],const int (&n)[max_x][max_y],int w,int h){
	for(int i=0; i<h;i++)
			for(int j=0; j< w;j++){
				ngrid[j][i]='.';
			}
		for(int i=0; i<h;i++)
			for(int j=0; j< w;j++){
				if(n[j][i]==2&&grid[j][i]=='0')
				ngrid[j][i]='0';
				if(n[j][i]==3)
				ngrid[j][i]='0';
				if(n[j][i]>=4)
				ngrid[j][i]='.';
			}
}
int main(){
	
	int h, w, gen;
	cout<<"Please enter the width of the grid :";
	cin >> w;
	while(w<1||w>max_x){
		cout<<"Error: The width of the grid must be an integer in [1, "<<max_x<<"]."<<endl;
		cout<<"Please enter the width of the grid :";
		cin>>w;
	}
	cout<<"Please enter the height of the grid :";
	cin>>h;
	while(h<1||h>max_y){
		cout<<"Error: The height of the grid must be an integer in [1, "<<max_y<<"]."<<endl;
		cout<<"Please enter the height of the grid :";
		cin>>h;
	}
	char grid[max_x][max_y];
	int n[max_x][max_y];
	initializer(grid,w,h);

	obtain(grid,w,h,gen);
	
	for(int g=0; g<=gen ;g++){
		display(grid,w,h,g);
				
		neighbor_calculator(n,grid,w,h);
		
		char ngrid[max_x][max_y];
		
		next_gen(ngrid,grid,n,w,h);
		for(int i=0; i<h;i++)
			for(int j=0; j< w;j++){
				grid[j][i]=ngrid[j][i];
			}
		
			
	}
}








