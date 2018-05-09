#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
#include<sstream>

using namespace std;
template <typename T>
string toString(T number){
	stringstream ss;
	ss <<number;
	return ss.str();
}
void path_to_neighbor(double** arr,double** map, int const* coor, int const* bound,bool** visited,string** pathway);

int main(){
	ifstream input("navigation_in.txt");
	int round, bound[2],init[2],dest[2];
	bool **is_used;
	double** path,**map;
	double inp;
	string name,**way,in;
	input>>round;
	for(int r=0;r<round;r++ ){
		input>>name>>bound[0]>>bound[1];
		input>>init[0]>>init[1]>>dest[0]>>dest[1];
		if((init[0]||init[1]||dest[0]||dest[1])<1||((init[0]||dest[0])>bound[0])||((init[1]||dest[1])>bound[1])){
			cout<<"INVALID_INPUT(invalid_starting/ending_position):"<<name<<endl;
		}
		cout<<name<<","<<bound[0]<<","<<bound[1]<<endl;
		cout<<"("<<init[0]<<","<<init[1]<<"),("<<dest[0]<<","<<dest[1]<<")\n";
		map= new double *[bound[1]];
		for(int i=0;i<bound[1];i++)
			map[i]= new double[bound[0]];
		getline(input,in);
		getline(input,in);
		getline(input,in);
		int y=1;
		for(int i = 0;i<in.length();i++){
			if(in[i]==' ')
			y++;
	
		}
		if(y<bound[0]*bound[1]||y>bound[0]*bound[1]){
		cout<<"INVALID_INPUT(invalid_grid size):"<<name<<endl;
		continue;
		}
		int k=0,l=0;
		cout<<in<<endl;
		istringstream ss(in);
		while(ss>>inp){
			map[k][l]=inp;
			l++;
			if(l==bound[1]){
				l=0;
				k++;
			}
			if(k==bound[0]) break;
		}
		
		for(int i =0 ; i<bound[1];i++){
			
			cout<<"|";
			for(int j=0; j<bound[0];j++){
				
				cout<<map[i][j]<<"|";
			}
			cout<<endl;
		}
		for(int q=0;q<2;q++){
			init[q]-=1;		
			dest[q]-=1;
		}
		
		is_used= new bool *[bound[1]];
		for(int i =0; i<bound[1];i++)
			is_used[i]=new bool [bound[0]];

		path= new double *[bound[1]];
		for(int i =0; i<bound[1];i++)
			path[i]=new double [bound[0]];
		for(int i =0 ; i<bound[1];i++)
			for(int j=0; j<bound[0];j++){
				is_used[i][j]=false;
				path[i][j]=bound[0]*bound[1]*2.0;
			}
		path[init[0]][init[1]]=map[init[0]][init[1]];
	
		way =new string *[bound[1]];
		for(int i=0;i<bound[1];i++)
			way[i] =new string [bound[0]];
		way[init[0]][init[1]]="("+toString(init[0]+1)+","+toString(init[1]+1)+")";
		path_to_neighbor(path,map,init , bound ,is_used,way);
		cout<<way[dest[0]][dest[1]]<<endl;
		cout<<"Shortest_Time:"<<path[dest[0]][dest[1]]<<endl;
		cout<<"Time_for_computation:"<<endl;
		cout<<endl;
	}
}

void path_to_neighbor(double** arr,double** map, int const* coor, int const* bound,bool** visited,string** pathway){
	string temp_coord;
	int p=0,temp[2];
	if(coor[0]>=0&&coor[1]>=0&&coor[0]<bound[0]&&coor[1]<bound[1]){
		
	if(visited[coor[0]][coor[1]]==false){
			
	
			
		for(int i=coor[0]-1;i<=coor[0]+1;i++){
			if(i<bound[0]&&i>=0){			
				
			for(int j=coor[1]-1;j<=coor[1]+1;j++){			
				if(j<bound[1]&&j>=0){
					if((i<coor[0]||i>coor[0])&&(j>coor[1]||j<coor[1])) continue;
				
					
				if((arr[coor[0]][coor[1]]+map[i][j])<arr[i][j]){
						pathway[i][j] =pathway[coor[0]][coor[1]]+",("+toString(i+1)+","+toString(j+1)+")";
					arr[i][j]= arr[coor[0]][coor[1]]+map[i][j];
				//	cout<<"("<<i<<","<<j<<") ="<<arr[i][j]<<" = "<<arr[coor[0]][coor[1]]<<" + "<<map[i][j]<<" coor = "<<coor[0]<<" "<<coor[1]<<endl;
					
					
				}
			
			}
			}
		}
		}
		
		visited[coor[0]][coor[1]]=true;
		double min =100000.0;
		for(int i=0;i<bound[1];i++){
						
			
			for(int j=0;j<bound[0];j++){			
				
				
					if(arr[i][j]<min&&visited[i][j]==false){
					min = arr[i][j];
					temp[0]=i;
					temp[1]=j;
				}
				
			}
			
		}
				path_to_neighbor(arr,map,temp,bound,visited,pathway);
			}
		}
	}
	

