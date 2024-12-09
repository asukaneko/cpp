#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main(){
    for(int t=1;t<=1000;t++){
        system("C:\\c++\\random.exe");//所有的\都要变为“\\”
        double st=clock();
        system("C:\\c++\\sol.exe");
        double ed=clock();
        system("C:\\c++\\bf.exe");
        if(system("fc C:\\c++\\data.ans C:\\c++\\data.out")){
        	puts("Wrong Answer");
        	return 0;
		}
		else{
			printf("Acceptd,测试点#%d,用时%.01fms\n",t,ed-st);
		}
    }
}