//#define VERSION_1   // - раскомментировать для активации версии 1
#define VERSION_2   // - раскомментировать для активации версии 2
#ifdef VERSION_2
/*==============================================
 ╔═══╗ ╔═════╗  ╔═════╗ ╔═════╗ ╔═╗     ╔═════╗
 ╚╣ ╠╝ ║ ╔═╗ ║  ║ ╔═╗ ║ ║ ╔═╗ ║ ║ ║     ║ ╔═╗ ║
  ║ ║  ║ ╚═╝ ║  ║ ║ ╚═╝ ║ ║ ║ ║ ║ ║     ║ ║ ╚═╝
  ║ ║  ║ ╔═══╝  ║ ║ ╔═╗ ║ ╚═╝ ║ ║ ║ ╔═╗ ║ ║ ╔═╗
 ╔╣ ╠╗ ║ ║      ║ ╚═╝ ║ ║ ╔═╗ ║ ║ ╚═╝ ║ ║ ╚═╝ ║
 ╚═══╝ ╚═╝      ╚═════╝ ╚═╝ ╚═╝ ╚═════╝ ╚═════╝
 ============ IP_CALCULATOR v2.0.0 ============
             property of bolofficial
                 on 20.03.2022
 ==============================================*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int MASK[33][4]{
    {0,  0,  0,  0  },
    {128,0,  0,  0  },
    {192,0,  0,  0  },
    {224,0,  0,  0  },
    {240,0,  0,  0  },
    {248,0,  0,  0  },
    {252,0,  0,  0  },
    {254,0,  0,  0  },
    {255,0,  0,  0  },
    {255,128,0,  0  },
    {255,192,0,  0  },
    {255,224,0,  0  },
    {255,240,0,  0  },
    {255,248,0,  0  },
    {255,252,0,  0  },
    {255,254,0,  0  },
    {255,255,0,  0  },
    {255,255,128,0  },
    {255,255,192,0  },
    {255,255,224,0  },
    {255,255,240,0  },
    {255,255,248,0  },
    {255,255,252,0  },
    {255,255,254,0  },
    {255,255,255,0  },
    {255,255,255,128},
    {255,255,255,192},
    {255,255,255,224},
    {255,255,255,240},
    {255,255,255,248},
    {255,255,255,252},
    {255,255,255,254},
    {255,255,255,255}
};

bool True(char p){
    if(p=='.'){return true;}
    return false;
}
bool True(int ip){
    if(ip>=0&&ip<=255){return true;}
    return false;
}
void input(int &ip1,char &p1,int &ip2,char &p2,int &ip3,char &p3,int &ip4,string name){
    while(true){
        cout<<name;
        cin>>ip1>>p1>>ip2>>p2>>ip3>>p3>>ip4;
        if((True(ip1))&&(True(p1))&&(True(ip2))&&(True(p2))&&(True(ip3))&&(True(p3))&&(True(ip4))){break;}
        cout<<"|ERROR: допускаются значения от 0 и до 255 или символ ( . )"<<endl;
    }
}
int BR(int ip,int mod){
    int br=0;
    while(true){
        br+=mod;
        if(br>=ip){return br;}
        br++;
    }
}
int main(int argc, const char * argv[]) {
    int ip1=0,ip2=0,ip3=0,ip4=0;
    char p1,p2,p3;
    
    int mask1=0,mask2=0,mask3=0,mask4=0;
    int number=-1;
    int temp_mod=0;
    int temp_div=0;
    int h=0;
    
    int br1=0,br2=0,br3=0,br4=0;
    
    int nw1=0,nw2=0,nw3=0,nw4=0;
    cout<<"+-------------+--------------------"<<endl;
    input(ip1,p1,ip2,p2,ip3,p3,ip4,"|  <Address>  | ");
    while(true){
        cout<<"|  <Netmask>  | ";
        cin>>number;
        if(number>=0&&number<=32){break;}
        cout<<"|ERROR:допускаются значения от 0 до 32"<<endl;
    }
    mask1 = MASK[number][0];
    mask2 = MASK[number][1];
    mask3 = MASK[number][2];
    mask4 = MASK[number][3];
    temp_mod =(32-number)%8;
    cout<<"temp_mod> "<<temp_mod<<endl;
    temp_div =4-(32-number)/8;
    h = pow(2, temp_mod)-1;
    cout<<"h> "<<h<<endl;
    if(number<9){
        br1=BR(ip1,h);
        nw1=br1-h;
        br2=br3=br4=255;
        nw2=nw3=nw4=0;
    }
    else if(number<17){
        br1=nw1=ip1;
        br2=BR(ip2,h);
        nw2=br2-h;
        br3=br4=255;
        nw3=nw4=0;
    }
    else if(number<25){
        br1=nw1=ip1;
        br2=nw2=ip2;
        br3=BR(ip3,h);
        nw3=br3-h;
        br4=255;
        nw4=0;
    }
    else{
        br1=nw1=ip1;
        br2=nw2=ip2;
        br3=nw3=ip3;
        br4=BR(ip4,h);
        nw4=br4-h;
    }
    cout<<"+-------------+--------------------"<<endl;
    cout<<"| <РЕЗУЛЬТАТ> "<<endl;
    cout<<"+-------------+--------------------"<<endl;
    cout<<"| <Address>   | "<<ip1<<p1<<ip2<<p2<<ip3<<p3<<ip4<<endl;
    cout<<"| <Netmask>   | "<<mask1<<p1<<mask2<<p2<<mask3<<p3<<mask4<<endl;
    cout<<"| <Network>   | "<<nw1<<p1<<nw2<<p2<<nw3<<p3<<nw4<<endl;
    cout<<"| <Broadcast> | "<<br1<<p1<<br2<<p2<<br3<<p3<<br4<<endl;
    cout<<"| <Hosts/Net> | "<<pow(2, (32-number))<<endl;
    cout<<"+-------------+--------------------"<<endl;
}
#endif VERSION_2

#ifdef VERSION_1
/*==============================================
 ╔═══╗ ╔═════╗  ╔═════╗ ╔═════╗ ╔═╗     ╔═════╗
 ╚╣ ╠╝ ║ ╔═╗ ║  ║ ╔═╗ ║ ║ ╔═╗ ║ ║ ║     ║ ╔═╗ ║
  ║ ║  ║ ╚═╝ ║  ║ ║ ╚═╝ ║ ║ ║ ║ ║ ║     ║ ║ ╚═╝
  ║ ║  ║ ╔═══╝  ║ ║ ╔═╗ ║ ╚═╝ ║ ║ ║ ╔═╗ ║ ║ ╔═╗
 ╔╣ ╠╗ ║ ║      ║ ╚═╝ ║ ║ ╔═╗ ║ ║ ╚═╝ ║ ║ ╚═╝ ║
 ╚═══╝ ╚═╝      ╚═════╝ ╚═╝ ╚═╝ ╚═════╝ ╚═════╝
 ============ IP_CALCULATOR v1.0.0 ============
             property of bolofficial
                  on 17.02.2022
 ==============================================*/
#include <iostream>
#include <cmath>
using namespace std;
int Point(int l,int r,string st);
string ToBIN(int bin);
int ToINT(int l,int r,string st);
int ToINT(string st);
bool TRUE_ST(string st,int &p1,int &p2,int &p3,int &p4);
int Network(int ip,int mask);
int Broadcast(int ip,int mask);
unsigned long int Hosts(int mask1,int mask2,int mask3,int mask4);
void Mask(int x,int &mask1,int &mask2,int &mask3,int &mask4);
void ERROR()
{
    cout<<"+------------------------------+"<<endl;
    cout<<" ERROR:неправильная форма ввода "<<endl;
    cout<<"+------------------------------+"<<endl;
}
string ONE(int x){
    string st;
    for(int i=0;i<x;i++){st+="1";}
    for(int i=x;i<8;i++){st+="0";}
    return st;
}
int main(int argc, const char * argv[]) {
    string ip = "";
    string mask = "";
    int ip1=0,ip2=0,ip3=0,ip4=0;
    int mask1=0,mask2=0,mask3=0,mask4=0;
    int temp=0;
    cout<<"+----------+--------------------"<<endl;
    while(true){
        cout<<"|IP address| ";
        cin>>ip;
        if(TRUE_ST(ip,ip1,ip2,ip3,ip4)==1){break;}
        ERROR();
    }
    while(true){
        cout<<"|Netmask:  | ";
        cin>>mask;
        if(mask.size()<3){
            temp = ToINT(0,mask.size(),mask);
            if(temp>=0&&temp<=32){Mask(temp, mask1, mask2, mask3, mask4); break;}
        }
        else{
            if(TRUE_ST(mask,mask1,mask2,mask3,mask4)==1){break;}
        }
        ERROR();
    }
    cout<<"+----------+--------------------"<<endl;
    cout<<"+----------+--------------------"<<endl;
    cout<<"|IP address|"<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<endl;
    cout<<"|MASK      |"<<mask1<<"."<<mask2<<"."<<mask3<<"."<<mask4<<endl;
    cout<<"|NETWORK   |"<<Network(ip1,mask1)<<"."<<Network(ip2,mask2)<<"."<<Network(ip3,mask3)<<"."<<Network(ip4,mask4)<<endl;
    cout<<"|BROADCAST |"<<Broadcast(ip1,mask1)<<"."<<Broadcast(ip2,mask2)<<"."<<Broadcast(ip3,mask3)<<"."<<Broadcast(ip4,mask4)<<endl;
    cout<<"|HOSTS     |"<<Hosts(mask1, mask2, mask3, mask4)<<endl;
    cout<<"+-------------------------------"<<endl;
}
int Point(int l,int r,string st){
    int p=0;
    for(int i=l;i<=r;i++)
    {
        if(st[i]=='.') {p = i; break;}
    }
    return p;
}
string ToBIN(int bin){
    string binint;
    string temp;
    while(bin>0){
        if(bin%2==1){temp+="1";}
        else{temp+="0";}
        bin = bin/2;
    }
    for(int i=0;i<8-temp.size();i++){binint+="0";}
    for(int i=temp.size()-1;i>=0;i--){binint+=temp[i];}
    return binint;
}
int ToINT(int l,int r,string st){
    int p=0;
    for(int i=l;i<r;i++)
    {
        p+=((int)st[i]-48)*pow(10,r-1-i);
    }
    return p;
}
int ToINT(string st){
    int x=0;
    for(int i=0;i<8;i++){
        if(st[i]=='1'){x+=pow(2,7-i);}
    }
    return x;
}
bool TRUE_ST(string st,int &p1,int &p2,int &p3,int &p4){
    int point1=0,point2=0,point3=0;
    int count1=0,count2=0;
    int size=st.size();
    for(int i=0;i<size;i++){
        if((int)st[i]>=48&&(int)st[i]<=57){count1++;}
        if(st[i]=='.'){count2++;}
    }
    if(st[size-1]=='.'){return 0;}
    if(count1+count2!=size){return 0;}
    if(count2>3){return 0;}
    point1 =Point(0,3,st);
    point2 =Point(point1+1,point1+4,st);
    point3 =Point(point2+1,point2+4,st);
    if(point1<1||point2<3||point3<5){return 0;}
    p1=ToINT(0,point1,st);
    p2=ToINT(point1+1,point2,st);
    p3=ToINT(point2+1,point3,st);
    p4=ToINT(point3+1,size,st);
    if(p1>255||p2>255||p3>255||p4>255){return 0;}
    return 1;
}
void Mask(int x,int &mask1,int &mask2,int &mask3,int &mask4){
    if(x==0){mask1=mask2=mask3=mask4=0;}
    if(x>0&&x<9){
        mask1=ToINT(ONE(x));
    }
    if(x>8&&x<17){
        mask1=255;
        mask2=ToINT(ONE(x-8));
    }
    if(x>16&&x<25){
        mask1=mask2=255;
        mask3=ToINT(ONE(x-8-8));
    }
    if(x>24){
        mask1=mask2=mask3=255;
        mask4=ToINT(ONE(x-8-8-8));
    }
}
unsigned long int Hosts(int mask1,int mask2,int mask3,int mask4){
    string m,m1,m2,m3,m4;
    unsigned long int hosts=0;
    m1=ToBIN(mask1);
    m2=ToBIN(mask2);
    m3=ToBIN(mask3);
    m4=ToBIN(mask4);
    m=m1+m2+m3+m4;
    for(int i=0;i<32;i++){
        if(m[i]=='0'){hosts++;}
    }
    hosts = pow(2,hosts)-2;
    return hosts;
}
int Broadcast(int ip,int mask){
    string IP = ToBIN(ip);
    string MASK = ToBIN(mask);
    string broadcast;
    int BROADCAST=0;
    for(int i=0;i<8;i++){
        if(MASK[i]=='1'){
            broadcast+=IP[i];
        }
        else{
            broadcast+="1";
        }
    }
    BROADCAST = ToINT(broadcast);
    return BROADCAST;
}
int Network(int ip,int mask){
    string IP = ToBIN(ip);
    string MASK = ToBIN(mask);
    string network;
    int NETWORK=0;
    for(int i=0;i<8;i++){
        if(IP[i]=='1'&&MASK[i]=='1'){
            network+="1";
        }
        else{
            network+="0";
        }
    }
    NETWORK = ToINT(network);
    return NETWORK;
}
#endif VERSION_1
