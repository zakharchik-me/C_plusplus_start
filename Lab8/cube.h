//
// Created by Anton Zakharov on 08.06.2022.
//

#ifndef LAB8_CUBE_H
#define LAB8_CUBE_H
#include <algorithm>
#include <vector>
using namespace std;
struct Cubee
{
    int x,y,z;
};
bool C(Cubee tmp, int i, int j, int z)
{
    if(tmp.x==i&&tmp.y==j&&tmp.z==z)return true;
    if(tmp.x==i&&tmp.y==z&&tmp.z==j)return true;
    if(tmp.x==j&&tmp.y==i&&tmp.z==z)return true;
    if(tmp.x==j&&tmp.y==z&&tmp.z==i)return true;
    if(tmp.x==z&&tmp.y==i&&tmp.z==j)return true;
    if(tmp.x==z&&tmp.y==j&&tmp.z==i)return true;
    return false;
}
class CubeSolver
{
private:
    Cubee p[27];
public:
    CubeSolver()
    {
        for(int i=0;i<27;i++) p[i]={0,0,0};
    }
    void enter_face(vector <vector<int>> tmp)
    {
        if(tmp[1][1]==1)
        {
            p[24].z=tmp[0][0]; p[25].z=tmp[0][1]; p[26].z=tmp[0][2];
            p[21].z=tmp[1][0]; p[22].z=tmp[1][1]; p[23].z=tmp[1][2];
            p[18].z=tmp[2][0]; p[19].z=tmp[2][1]; p[20].z=tmp[2][2];
            return;
        }
        if(tmp[1][1]==2)
        {
            p[24].y=tmp[0][0]; p[21].y=tmp[0][1]; p[18].y=tmp[0][2];
            p[15].y=tmp[1][0]; p[12].y=tmp[1][1]; p[9].y=tmp[1][2];
            p[6].y=tmp[2][0]; p[3].y=tmp[2][1]; p[0].y=tmp[2][2];
            return;
        }
        if(tmp[1][1]==3)
        {
            p[18].x=tmp[0][0]; p[19].x=tmp[0][1]; p[20].x=tmp[0][2];
            p[9].x=tmp[1][0]; p[10].x=tmp[1][1]; p[11].x=tmp[1][2];
            p[0].x=tmp[2][0]; p[1].x=tmp[2][1]; p[2].x=tmp[2][2];
            return;
        }
        if(tmp[1][1]==4)
        {
            p[20].y=tmp[0][0]; p[23].y=tmp[0][1]; p[26].y=tmp[0][2];
            p[11].y=tmp[1][0]; p[14].y=tmp[1][1]; p[17].y=tmp[1][2];
            p[2].y=tmp[2][0]; p[5].y=tmp[2][1]; p[8].y=tmp[2][2];
            return;
        }
        if(tmp[1][1]==5)
        {
            p[26].x=tmp[0][0]; p[25].x=tmp[0][1]; p[24].x=tmp[0][2];
            p[17].x=tmp[1][0]; p[16].x=tmp[1][1]; p[15].x=tmp[1][2];
            p[8].x=tmp[2][0]; p[7].x=tmp[2][1]; p[6].x=tmp[2][2];
            return;
        }
        if(tmp[1][1]==6)
        {
            p[0].z=tmp[0][0]; p[1].z=tmp[0][1]; p[2].z=tmp[0][2];
            p[3].z=tmp[1][0]; p[4].z=tmp[1][1]; p[5].z=tmp[1][2];
            p[6].z=tmp[2][0]; p[7].z=tmp[2][1]; p[8].z=tmp[2][2];
            return;
        }
    }
    void print_all_face()
    {
        cout<<"face 1\n";
        cout<<p[24].z<<" "<<p[25].z<<" "<<p[26].z<<"\n";
        cout<<p[21].z<<" "<<p[22].z<<" "<<p[23].z<<"\n";
        cout<<p[18].z<<" "<<p[19].z<<" "<<p[20].z<<"\n";
        cout<<"\nface 2\n";
        cout<<p[24].y<<" "<<p[21].y<<" "<<p[18].y<<"\n";
        cout<<p[15].y<<" "<<p[12].y<<" "<<p[9].y<<"\n";
        cout<<p[6].y<<" "<<p[3].y<<" "<<p[0].y<<"\n";
        cout<<"face 3\n";
        cout<<p[18].x<<" "<<p[19].x<<" "<<p[20].x<<"\n";
        cout<<p[9].x<<" "<<p[10].x<<" "<<p[11].x<<"\n";
        cout<<p[0].x<<" "<<p[1].x<<" "<<p[2].x<<"\n";
        cout<<"face 4\n";
        cout<<p[20].y<<" "<<p[23].y<<" "<<p[26].y<<"\n";
        cout<<p[11].y<<" "<<p[14].y<<" "<<p[17].y<<"\n";
        cout<<p[2].y<<" "<<p[5].y<<" "<<p[8].y<<"\n";
        cout<<"face 5\n";
        cout<<p[26].x<<" "<<p[25].x<<" "<<p[24].x<<"\n";
        cout<<p[17].x<<" "<<p[16].x<<" "<<p[15].x<<"\n";
        cout<<p[8].x<<" "<<p[7].x<<" "<<p[6].x<<"\n";
        cout<<"face 6\n";
        cout<<p[0].z<<" "<<p[1].z<<" "<<p[2].z<<"\n";
        cout<<p[3].z<<" "<<p[4].z<<" "<<p[5].z<<"\n";
        cout<<p[6].z<<" "<<p[7].z<<" "<<p[8].z<<"\n";

    }
    bool is_cube_wrong()
    {
        int t[]={0,0,0,0,0,0,0}; string s[]={"","while","orange","green","red","blue","yellow"}; bool kt=false;
        for(auto & i : p)
        {
            t[i.x]++;
            t[i.y]++;
            t[i.z]++;
        }
        for(int i=1;i<7;i++)
            if(t[i]!=9) {kt=true; break;}
        if(!kt) return false;
        for(int i=1;i<7;i++)
            cout<<s[i]<<" "<<t[i]<<"\n"; return true;
    }
    void R()
    {
        CubeSolver tmp = (*this); cout << "R ";
        p[26]=tmp.p[20]; swap(p[26].x,p[26].z); p[2]=tmp.p[8]; swap(p[2].x,p[2].z);
        p[20]=tmp.p[2]; swap(p[20].x,p[20].z); p[8]=tmp.p[26]; swap(p[8].x,p[8].z);
        p[17]=tmp.p[23]; swap(p[17].x,p[17].z); p[5]=tmp.p[17]; swap(p[5].x,p[5].z);
        p[11]=tmp.p[5]; swap(p[11].x,p[11].z); p[23]=tmp.p[11]; swap(p[23].x,p[23].z);
    }
    void R_()
    {
        CubeSolver tmp = (*this); cout << "R' ";
        p[20]=tmp.p[26]; swap(p[20].x,p[20].z); p[8]=tmp.p[2]; swap(p[8].x,p[8].z);
        p[26]=tmp.p[8]; swap(p[26].x,p[26].z); p[2]=tmp.p[20]; swap(p[2].x,p[2].z);
        p[17]=tmp.p[5]; swap(p[17].x,p[17].z); p[5]=tmp.p[11]; swap(p[5].x,p[5].z);
        p[11]=tmp.p[23]; swap(p[11].x,p[11].z); p[23]=tmp.p[17]; swap(p[23].x,p[23].z);
    }
    void L()
    {
        CubeSolver tmp = (*this); cout << "L' ";
        p[18]=tmp.p[0]; swap(p[18].x,p[18].z); p[0]=tmp.p[6]; swap(p[0].x,p[0].z);
        p[24]=tmp.p[18]; swap(p[24].x,p[24].z); p[6]=tmp.p[24]; swap(p[6].x,p[6].z);
        p[21]=tmp.p[9]; swap(p[21].x,p[21].z); p[15]=tmp.p[21]; swap(p[15].x,p[15].z);
        p[3]=tmp.p[15]; swap(p[3].x,p[3].z); p[9]=tmp.p[3]; swap(p[9].x,p[9].z);
    }
    void L_()
    {
        CubeSolver tmp = (*this); cout << "L ";
        p[18]=tmp.p[24]; swap(p[18].x,p[18].z); p[0]=tmp.p[18]; swap(p[0].x,p[0].z);
        p[24]=tmp.p[6]; swap(p[24].x,p[24].z); p[6]=tmp.p[0]; swap(p[6].x,p[6].z);
        p[21]=tmp.p[15]; swap(p[21].x,p[21].z); p[15]=tmp.p[3]; swap(p[15].x,p[15].z);
        p[3]=tmp.p[9]; swap(p[3].x,p[3].z); p[9]=tmp.p[21]; swap(p[9].x,p[9].z);
    }
    void U()
    {
        CubeSolver tmp = (*this); cout << "U ";
        p[24]=tmp.p[18]; swap(p[24].x,p[24].y); p[18]=tmp.p[20]; swap(p[18].x,p[18].y);
        p[26]=tmp.p[24]; swap(p[26].x,p[26].y); p[20]=tmp.p[26]; swap(p[20].x,p[20].y);
        p[21]=tmp.p[19]; swap(p[21].x,p[21].y); p[25]=tmp.p[21]; swap(p[25].x,p[25].y);
        p[23]=tmp.p[25]; swap(p[23].x,p[23].y); p[19]=tmp.p[23]; swap(p[19].x,p[19].y);
    }
    void U_()
    {
        CubeSolver tmp = (*this); cout << "U' ";
        p[24]=tmp.p[26]; swap(p[24].x,p[24].y); p[18]=tmp.p[24]; swap(p[18].x,p[18].y);
        p[26]=tmp.p[20]; swap(p[26].x,p[26].y); p[20]=tmp.p[18]; swap(p[20].x,p[20].y);
        p[21]=tmp.p[25]; swap(p[21].x,p[21].y); p[25]=tmp.p[23]; swap(p[25].x,p[25].y);
        p[23]=tmp.p[19]; swap(p[23].x,p[23].y); p[19]=tmp.p[21]; swap(p[19].x,p[19].y);
    }
    void D()
    {
        CubeSolver tmp = (*this); cout << "D ";
        p[6]=tmp.p[8]; swap(p[6].x,p[6].y); p[8]=tmp.p[2]; swap(p[8].x,p[8].y);
        p[0]=tmp.p[6]; swap(p[0].x,p[0].y); p[2]=tmp.p[0]; swap(p[2].x,p[2].y);
        p[7]=tmp.p[5]; swap(p[7].x,p[7].y); p[5]=tmp.p[1]; swap(p[5].x,p[5].y);
        p[1]=tmp.p[3]; swap(p[1].x,p[1].y); p[3]=tmp.p[7]; swap(p[3].x,p[3].y);
    }
    void D_()
    {
        CubeSolver tmp = (*this); cout << "D' ";
        p[6]=tmp.p[0]; swap(p[6].x,p[6].y); p[8]=tmp.p[6]; swap(p[8].x,p[8].y);
        p[0]=tmp.p[2]; swap(p[0].x,p[0].y); p[2]=tmp.p[8]; swap(p[2].x,p[2].y);
        p[7]=tmp.p[3]; swap(p[7].x,p[7].y); p[5]=tmp.p[7]; swap(p[5].x,p[5].y);
        p[1]=tmp.p[5]; swap(p[1].x,p[1].y); p[3]=tmp.p[1]; swap(p[3].x,p[3].y);
    }
    void F()
    {
        CubeSolver tmp = (*this); cout << "F ";
        p[18]=tmp.p[0]; swap(p[18].z,p[18].y); p[20]=tmp.p[18]; swap(p[20].z,p[20].y);
        p[0]=tmp.p[2]; swap(p[0].z,p[0].y); p[2]=tmp.p[20]; swap(p[2].z,p[2].y);
        p[19]=tmp.p[9]; swap(p[19].z,p[19].y); p[11]=tmp.p[19]; swap(p[11].z,p[11].y);
        p[1]=tmp.p[11]; swap(p[1].z,p[1].y); p[9]=tmp.p[1]; swap(p[9].z,p[9].y);
    }
    void F_()
    {
        CubeSolver tmp = (*this); cout << "F' ";
        p[18]=tmp.p[20]; swap(p[18].z,p[18].y); p[20]=tmp.p[2]; swap(p[20].z,p[20].y);
        p[0]=tmp.p[18]; swap(p[0].z,p[0].y); p[2]=tmp.p[0]; swap(p[2].z,p[2].y);
        p[19]=tmp.p[11]; swap(p[19].z,p[19].y); p[11]=tmp.p[1]; swap(p[11].z,p[11].y);
        p[1]=tmp.p[9]; swap(p[1].z,p[1].y); p[9]=tmp.p[19]; swap(p[9].z,p[9].y);
    }
    void B()
    {
        CubeSolver tmp = (*this); cout << "B' ";
        p[24]=tmp.p[6]; swap(p[24].z,p[24].y); p[26]=tmp.p[24]; swap(p[26].z,p[26].y);
        p[8]=tmp.p[26]; swap(p[8].z,p[8].y); p[6]=tmp.p[8]; swap(p[6].z,p[6].y);
        p[25]=tmp.p[15]; swap(p[25].z,p[25].y); p[17]=tmp.p[25]; swap(p[17].z,p[17].y);
        p[7]=tmp.p[17]; swap(p[7].z,p[7].y); p[15]=tmp.p[7]; swap(p[15].z,p[15].y);
    }
    void B_()
    {
        CubeSolver tmp = (*this); cout << "B ";
        p[24]=tmp.p[26]; swap(p[24].z,p[24].y); p[26]=tmp.p[8]; swap(p[26].z,p[26].y);
        p[8]=tmp.p[6]; swap(p[8].z,p[8].y); p[6]=tmp.p[24]; swap(p[6].z,p[6].y);
        p[25]=tmp.p[17]; swap(p[25].z,p[25].y); p[17]=tmp.p[7]; swap(p[17].z,p[17].y);
        p[7]=tmp.p[15]; swap(p[7].z,p[7].y); p[15]=tmp.p[25]; swap(p[15].z,p[15].y);
    }
    void solve_cross()
    {
        while(p[23].z!=1||p[23].y!=4)
        {
            if(p[23].y==1&&p[23].z==4){(*this).R_(); (*this).F_(); (*this).U_(); continue;}
            if(p[11].x==4&&p[11].y==1){(*this).U(); (*this).F_(); (*this).U_(); cout<<"\n"; break;}
            if(p[11].x==1&&p[11].y==4){(*this).R(); cout<<"\n"; break;}
            if(p[19].x==4&&p[19].z==1){(*this).U_(); cout<<"\n"; break;}
            if(p[19].x==1&&p[19].z==4){(*this).F(); (*this).R(); cout<<"\n"; break;}
            if((p[1].x==4&&p[1].z==1)||(p[1].x==1&&p[1].z==4)){(*this).U(); (*this).F_(); (*this).F_(); (*this).U_(); continue;}

            if((p[17].x==1&&p[17].y==4)||(p[17].x==4&&p[17].y==1)){(*this).R_(); continue;}
            if((p[5].y==4&&p[5].z==1)||(p[5].y==1&&p[5].z==4)){(*this).R_(); (*this).R_(); continue;}

            if((p[9].x==4&&p[9].y==1)||(p[9].x==1&&p[9].y==4)){(*this).F(); (*this).U_(); continue;}
            if((p[21].y==4&&p[21].z==1)||(p[21].y==1&&p[21].z==4)){(*this).U(); (*this).U(); continue;}
            if((p[15].y==4&&p[15].x==1)||(p[15].y==1&&p[15].x==4)){(*this).B(); (*this).B(); (*this).R_(); continue;}
            if((p[3].y==4&&p[3].z==1)||(p[3].y==1&&p[3].z==4)){(*this).D_(); (*this).D_(); continue;}

            if((p[25].x==1&&p[25].z==4)||(p[25].x==4&&p[25].z==1)){ (*this).U(); continue;}
            if((p[7].x==1&&p[7].z==4)||(p[7].x==4&&p[7].z==1)){(*this).D_(); (*this).R_(); (*this).R_(); continue;}
        }
        while(p[19].z!=1||p[19].x!=3)
        {

            if(p[19].x==1&&p[19].z==3){(*this).F(); (*this).U_(); (*this).R(); (*this).U(); cout<<"\n"; break;}
            if(p[11].x==1&&p[11].y==3){(*this).U_(); (*this).R(); (*this).U(); cout<<"\n"; break;}
            if(p[11].x==3&&p[11].y==1){(*this).F_(); cout<<"\n"; break;}
            if(p[11].x==1&&p[11].y==3){(*this).U_(); (*this).R(); (*this).U(); cout<<"\n"; break;}
            if((p[1].x==1&&p[1].z==3)||(p[1].x==3&&p[1].z==1)){(*this).F_(); continue;}
            if((p[9].x==1&&p[9].y==3)||(p[9].x==3&&p[9].y==1)){(*this).F(); continue;}

            if((p[23].z==1&&p[23].y==3)||(p[23].z==3&&p[23].y==1)){(*this).R_(); continue;}
            if((p[17].x==1&&p[23].y==3)||(p[17].x==3&&p[17].y==1)){(*this).U_(); (*this).R_(); (*this).R_(); (*this).U(); continue;}
            if((p[5].y==1&&p[5].z==3)||(p[5].y==3&&p[5].z==1)){(*this).D_(); continue;}

            if((p[3].y==1&&p[3].z==3)||(p[3].y==3&&p[3].z==1)){(*this).D(); continue;}
            if((p[7].x==1&&p[7].z==3)||(p[7].x==3&&p[7].z==1)){(*this).D(); (*this).D(); continue;}

            if((p[25].x==1&&p[25].z==3)||(p[25].x==3&&p[25].z==1)){(*this).B(); continue;}
            if((p[21].y==1&&p[21].z==3)||(p[21].y==3&&p[21].z==1)){(*this).L_(); continue;}

            if((p[15].x==1&&p[15].y==3)||(p[15].x==3&&p[15].y==1)){(*this).U(); (*this).L();  (*this).U_();continue;}
        }

        while(p[25].z!=1||p[25].x!=5)
        {
            if(p[25].z==5&&p[25].x==1){(*this).B(); (*this).U(); (*this).R_(); (*this).U_(); cout<<"\n"; break;}
            if(p[17].x==5&&p[17].y==1){(*this).B_(); cout<<"\n"; break;}
            if(p[17].x==1&&p[17].y==5){(*this).U(); (*this).R_(); (*this).U_(); cout<<"\n"; break;}
            if((p[7].x==1&&p[7].z==5)||(p[7].x==5&&p[7].z==1)){(*this).B_(); continue;}
            if((p[15].x==1&&p[15].y==5)||(p[15].x==5&&p[15].y==1)){(*this).B(); continue;}

            if((p[5].z==1&&p[5].y==5)||(p[5].z==5&&p[5].y==1)){(*this).D(); continue;}
            if((p[3].z==1&&p[3].y==5)||(p[3].z==5&&p[3].y==1)){(*this).D_(); continue;}
            if((p[1].z==1&&p[3].x==5)||(p[1].z==5&&p[1].x==1)){(*this).D(); (*this).D(); continue;}

            if((p[23].y==1&&p[23].z==5)||(p[23].y==5&&p[23].z==1)){(*this).R(); continue;}
            if((p[11].y==1&&p[11].x==5)||(p[11].y==5&&p[11].x==1)){(*this).U(); (*this).R(); (*this).U_(); continue;}

            if((p[19].x==1&&p[19].z==5)||(p[19].x==5&&p[19].z==1)){(*this).F(); (*this).F(); continue;}
            if((p[21].y==1&&p[21].z==5)||(p[21].y==5&&p[21].z==1)){(*this).L(); continue;}

            if((p[9].y==1&&p[9].x==5)||(p[9].y==5&&p[9].x==1)){(*this).L(); (*this).L(); continue;}
            return;
        }
        while(p[21].z!=1||p[21].y!=2)
        {

            if(p[21].z==2&&p[21].y==1){(*this).L_(); (*this).U_(); (*this).F(); (*this).U(); cout<<"\n"; break;}
            if(p[9].x==1&&p[9].y==2){(*this).L(); cout<<"\n"; break;}
            if(p[9].x==2&&p[9].y==1){(*this).U_(); (*this).F(); (*this).U(); cout<<"\n"; break;}
            if((p[3].z==1&&p[3].y==2)||(p[3].z==2&&p[3].y==1)){(*this).L(); continue;}
            if((p[15].x==1&&p[15].y==2)||(p[15].x==2&&p[15].y==1)){(*this).L_(); continue;}

            if((p[7].x==1&&p[7].z==2)||(p[7].x==2&&p[7].z==1)){(*this).D(); continue;}
            if((p[1].x==1&&p[1].z==2)||(p[1].x==2&&p[1].z==1)){(*this).D_(); continue;}
            if((p[5].y==1&&p[5].z==2)||(p[5].y==2&&p[5].z==1)){(*this).D(); (*this).D(); continue;}

            if((p[19].x==1&&p[19].z==2)||(p[19].x==2&&p[19].z==1)){(*this).F_(); continue;}
            if((p[11].x==1&&p[11].y==2)||(p[11].x==2&&p[11].y==1)){(*this).U_(); (*this).F_(); (*this).U(); continue;}

            if((p[25].x==1&&p[25].z==2)||(p[25].x==2&&p[25].z==1)){(*this).B(); (*this).B(); continue;}
            if((p[23].z==1&&p[23].y==2)||(p[23].z==2&&p[23].y==1)){(*this).R(); (*this).R(); continue;}

            if((p[17].x==1&&p[17].y==2)||(p[17].x==2&&p[17].y==1)){(*this).U(); (*this).B_(); (*this).U_(); continue;}

        }
        return ;
    }
    void solve_layer_first()
    {
        solve_cross();
        while(p[20].x!=3||p[20].y!=4||p[20].z!=1)
        {
            if(C(p[20],1,3,4)) {(*this).R_(); (*this).D_(); (*this).R();}
            if(p[2].x==1&&p[2].y==4&&p[2].z==3){(*this).R(); (*this).F_(); (*this).R_(); (*this).F(); cout<<"\n"; break;}
            if(p[2].x==3&&p[2].y==1&&p[2].z==4){(*this).F_(); (*this).R(); (*this).F(); (*this).R_(); cout<<"\n"; break;}
            if(p[2].x==4&&p[2].y==3&&p[2].z==1){(*this).F(); (*this).D_(); (*this).F_(); (*this).D();(*this).D(); continue;}

            if(C(p[0],1,3,4)) {(*this).D(); continue;}
            if(C(p[6],1,3,4)) {(*this).D_(); (*this).D_(); continue;}
            if(C(p[8],1,3,4)) {(*this).D_(); continue;}
            if(C(p[26],1,3,4)) {(*this).R(); (*this).D(); (*this).R_(); (*this).D(); (*this).D(); continue;}
            if(C(p[24],1,3,4)) {(*this).L(); (*this).D(); (*this).D(); (*this).L_(); continue;}
            if(C(p[18],1,3,4)) {(*this).L_(); (*this).D(); (*this).L(); continue;}
        }
        while(p[18].x!=3||p[18].y!=2||p[18].z!=1)
        {
            if(C(p[18],1,2,3)) {(*this).F_(); (*this).D_(); (*this).F(); (*this).D();}
            if(p[0].x==3&&p[0].y==1&&p[0].z==2){(*this).F(); (*this).L(); (*this).F_(); (*this).L_(); cout<<"\n"; break;}
            if(p[0].x==1&&p[0].y==2&&p[0].z==3){(*this).L(); (*this).F(); (*this).L_(); (*this).F_(); cout<<"\n"; break;}
            if(p[0].x==2&&p[0].y==3&&p[0].z==1){(*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).D_(); continue;}

            if(C(p[24],1,2,3)) {(*this).B_(); (*this).D(); (*this).B(); continue;}
            if(C(p[26],1,2,3)) {(*this).R(); (*this).D(); (*this).D(); (*this).R_(); continue;}
            if(C(p[20],1,2,3)) {(*this).R_(); (*this).D_(); (*this).R(); continue;}
            if(C(p[2],1,2,3)) {(*this).D_(); continue;}
            if(C(p[8],1,2,3)) {(*this).D(); (*this).D(); continue;}
            if(C(p[6],1,2,3)) {(*this).D(); continue;}
        }
        while(p[24].x!=5||p[24].y!=2||p[24].z!=1)
        {
            if(C(p[24],1,2,5)) {(*this).B_(); (*this).D(); (*this).B(); (*this).D_(); continue;}
            if(p[6].x==5&&p[6].y==1&&p[6].z==2){(*this).B(); (*this).L_(); (*this).B_(); (*this).L(); cout<<"\n"; break;}
            if(p[6].x==1&&p[6].y==2&&p[6].z==5){(*this).L_(); (*this).B(); (*this).L(); (*this).B_(); cout<<"\n"; break;}
            if(p[6].x==2&&p[6].y==5&&p[6].z==1){(*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).D_(); continue;}

            if(C(p[26],1,2,5)) {(*this).R(); (*this).D(); (*this).R_();continue;}
            if(C(p[8],1,2,5)) {(*this).D(); continue;}
            if(C(p[2],1,2,5)) {(*this).D_(); (*this).D_(); continue;}
            if(C(p[0],1,2,5)) {(*this).D_(); continue;}
        }
        while(p[26].x!=5||p[26].y!=4||p[26].z!=1)
        {
            if(C(p[26],1,4,5)){(*this).B(); (*this).D_(); (*this).B_(); (*this).D(); continue;}
            if(p[8].x==1&&p[8].y==4&&p[8].z==5){(*this).R_(); (*this).B_(); (*this).R(); (*this).B(); cout<<"\n"; break;}
            if(p[8].x==5&&p[8].y==1&&p[8].z==4){(*this).B_(); (*this).R_(); (*this).B(); (*this).R(); cout<<"\n"; break;}
            if(p[8].x==4&&p[8].y==5&&p[8].z==1) {(*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).D_(); continue;}

            if(C(p[6],1,4,5)){(*this).D_();  continue;}
            if(C(p[0],1,4,5)){(*this).D(); (*this).D(); continue;}
            if(C(p[2],1,4,5)){(*this).D(); continue;}
        }
    }
    void solve_layer_second()
    {
        if(p[1].x==3&&p[1].z==2){(*this).D(); (*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).F_(); (*this).D(); (*this).F(); cout<<"\n";}
        if(p[1].x==3&&p[1].z==4){(*this).D_(); (*this).R_(); (*this).D(); (*this).R(); (*this).D(); (*this).F(); (*this).D_(); (*this).F_(); cout<<"\n";}

        if(p[5].y==4&&p[5].z==3){(*this).D(); (*this).F(); (*this).D_(); (*this).F_(); (*this).D_(); (*this).R_(); (*this).D(); (*this).R(); cout<<"\n";}
        if(p[5].y==4&&p[5].z==5){(*this).D_(); (*this).B(); (*this).D(); (*this).B_(); (*this).D(); (*this).R(); (*this).D_(); (*this).R_(); cout<<"\n";}

        if(p[7].x==5&&p[7].z==4){(*this).D(); (*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).B(); (*this).D(); (*this).B_(); cout<<"\n";}
        if(p[7].x==5&&p[7].z==2){(*this).D_(); (*this).L(); (*this).D(); (*this).L_(); (*this).D(); (*this).B_(); (*this).D_(); (*this).B(); cout<<"\n";}

        if(p[3].y==2&&p[3].z==5){(*this).D(); (*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).L(); (*this).D(); (*this).L_(); cout<<"\n";}
        if(p[3].y==2&&p[3].z==3){(*this).D_(); (*this).F_(); (*this).D(); (*this).F(); (*this).D(); (*this).L_(); (*this).D_(); (*this).L(); cout<<"\n";}

        while(!(p[11].x==3&&p[11].y==4)||!(p[17].x==5&&p[17].y==4)||!(p[9].x==3&&p[9].y==2)||!(p[15].x==5&&p[15].y==2))
        {
            if(!(p[15].x==5&&p[15].y==2))
            {
                if(p[15].x!=6&&p[15].y!=6){(*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).L(); (*this).D(); (*this).L_(); cout<<"\n";}
                for(int i=0;i<4;i++)
                {
                    if(p[1].x==3&&p[1].z==2){(*this).D(); (*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).F_(); (*this).D(); (*this).F(); cout<<"\n";}
                    if(p[1].x==3&&p[1].z==4){(*this).D_(); (*this).R_(); (*this).D(); (*this).R(); (*this).D(); (*this).F(); (*this).D_(); (*this).F_(); cout<<"\n";}

                    if(p[5].y==4&&p[5].z==3){(*this).D(); (*this).F(); (*this).D_(); (*this).F_(); (*this).D_(); (*this).R_(); (*this).D(); (*this).R(); cout<<"\n";}
                    if(p[5].y==4&&p[5].z==5){(*this).D_(); (*this).B(); (*this).D(); (*this).B_(); (*this).D(); (*this).R(); (*this).D_(); (*this).R_(); cout<<"\n";}

                    if(p[7].x==5&&p[7].z==4){(*this).D(); (*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).B(); (*this).D(); (*this).B_(); cout<<"\n";}
                    if(p[7].x==5&&p[7].z==2){(*this).D_(); (*this).L(); (*this).D(); (*this).L_(); (*this).D(); (*this).B_(); (*this).D_(); (*this).B(); cout<<"\n";}

                    if(p[3].y==2&&p[3].z==5){(*this).D(); (*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).L(); (*this).D(); (*this).L_(); cout<<"\n";}
                    if(p[3].y==2&&p[3].z==3){(*this).D_(); (*this).F_(); (*this).D(); (*this).F(); (*this).D(); (*this).L_(); (*this).D_(); (*this).L(); cout<<"\n";}

                    (*this).D();
                }
            }
            if(!(p[17].x==5&&p[17].y==4))
            {
                if(p[17].x!=6&&p[17].y!=6){(*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).B(); (*this).D(); (*this).B_(); cout<<"\n";}
                for(int i=0;i<4;i++)
                {
                    if(p[1].x==3&&p[1].z==2){(*this).D(); (*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).F_(); (*this).D(); (*this).F(); cout<<"\n";}
                    if(p[1].x==3&&p[1].z==4){(*this).D_(); (*this).R_(); (*this).D(); (*this).R(); (*this).D(); (*this).F(); (*this).D_(); (*this).F_(); cout<<"\n";}

                    if(p[5].y==4&&p[5].z==3){(*this).D(); (*this).F(); (*this).D_(); (*this).F_(); (*this).D_(); (*this).R_(); (*this).D(); (*this).R(); cout<<"\n";}
                    if(p[5].y==4&&p[5].z==5){(*this).D_(); (*this).B(); (*this).D(); (*this).B_(); (*this).D(); (*this).R(); (*this).D_(); (*this).R_(); cout<<"\n";}

                    if(p[7].x==5&&p[7].z==4){(*this).D(); (*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).B(); (*this).D(); (*this).B_(); cout<<"\n";}
                    if(p[7].x==5&&p[7].z==2){(*this).D_(); (*this).L(); (*this).D(); (*this).L_(); (*this).D(); (*this).B_(); (*this).D_(); (*this).B(); cout<<"\n";}

                    if(p[3].y==2&&p[3].z==5){(*this).D(); (*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).L(); (*this).D(); (*this).L_(); cout<<"\n";}
                    if(p[3].y==2&&p[3].z==3){(*this).D_(); (*this).F_(); (*this).D(); (*this).F(); (*this).D(); (*this).L_(); (*this).D_(); (*this).L(); cout<<"\n";}

                    (*this).D();
                }
            }
            if(!(p[11].x==3&&p[11].y==4))
            {
                if(p[11].x!=6&&p[11].y!=6){(*this).F(); (*this).D_(); (*this).F_(); (*this).D_(); (*this).R_(); (*this).D(); (*this).R(); cout<<"\n";}
                for(int i=0;i<4;i++)
                {
                    if(p[1].x==3&&p[1].z==2){(*this).D(); (*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).F_(); (*this).D(); (*this).F(); cout<<"\n";}
                    if(p[1].x==3&&p[1].z==4){(*this).D_(); (*this).R_(); (*this).D(); (*this).R(); (*this).D(); (*this).F(); (*this).D_(); (*this).F_(); cout<<"\n";}

                    if(p[5].y==4&&p[5].z==3){(*this).D(); (*this).F(); (*this).D_(); (*this).F_(); (*this).D_(); (*this).R_(); (*this).D(); (*this).R(); cout<<"\n";}
                    if(p[5].y==4&&p[5].z==5){(*this).D_(); (*this).B(); (*this).D(); (*this).B_(); (*this).D(); (*this).R(); (*this).D_(); (*this).R_(); cout<<"\n";}

                    if(p[7].x==5&&p[7].z==4){(*this).D(); (*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).B(); (*this).D(); (*this).B_(); cout<<"\n";}
                    if(p[7].x==5&&p[7].z==2){(*this).D_(); (*this).L(); (*this).D(); (*this).L_(); (*this).D(); (*this).B_(); (*this).D_(); (*this).B(); cout<<"\n";}

                    if(p[3].y==2&&p[3].z==5){(*this).D(); (*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).L(); (*this).D(); (*this).L_(); cout<<"\n";}
                    if(p[3].y==2&&p[3].z==3){(*this).D_(); (*this).F_(); (*this).D(); (*this).F(); (*this).D(); (*this).L_(); (*this).D_(); (*this).L(); cout<<"\n";}

                    (*this).D();
                }
            }
            if(!(p[9].x==3&&p[9].y==2))
            {
                if(p[9].x!=6&&p[9].y!=6){(*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).F_(); (*this).D(); (*this).F(); cout<<"\n";}
                for(int i=0;i<4;i++)
                {
                    if(p[1].x==3&&p[1].z==2){(*this).D(); (*this).L_(); (*this).D_(); (*this).L(); (*this).D_(); (*this).F_(); (*this).D(); (*this).F(); cout<<"\n";}
                    if(p[1].x==3&&p[1].z==4){(*this).D_(); (*this).R_(); (*this).D(); (*this).R(); (*this).D(); (*this).F(); (*this).D_(); (*this).F_(); cout<<"\n";}

                    if(p[5].y==4&&p[5].z==3){(*this).D(); (*this).F(); (*this).D_(); (*this).F_(); (*this).D_(); (*this).R_(); (*this).D(); (*this).R(); cout<<"\n";}
                    if(p[5].y==4&&p[5].z==5){(*this).D_(); (*this).B(); (*this).D(); (*this).B_(); (*this).D(); (*this).R(); (*this).D_(); (*this).R_(); cout<<"\n";}

                    if(p[7].x==5&&p[7].z==4){(*this).D(); (*this).R(); (*this).D_(); (*this).R_(); (*this).D_(); (*this).B(); (*this).D(); (*this).B_(); cout<<"\n";}
                    if(p[7].x==5&&p[7].z==2){(*this).D_(); (*this).L(); (*this).D(); (*this).L_(); (*this).D(); (*this).B_(); (*this).D_(); (*this).B(); cout<<"\n";}

                    if(p[3].y==2&&p[3].z==5){(*this).D(); (*this).B_(); (*this).D_(); (*this).B(); (*this).D_(); (*this).L(); (*this).D(); (*this).L_(); cout<<"\n";}
                    if(p[3].y==2&&p[3].z==3){(*this).D_(); (*this).F_(); (*this).D(); (*this).F(); (*this).D(); (*this).L_(); (*this).D_(); (*this).L(); cout<<"\n";}

                    (*this).D();
                }
            }
        }
    }
    void solve_layer_last()
    {
        while(p[1].z!=6||p[3].z!=6||p[5].z!=6||p[7].z!=6)
        {
            if( p[7].z==6 && p[1].z==6 )
            {
                (*this).L_(); (*this).B_(); (*this).D(); (*this).B(); (*this).D_(); (*this).L(); cout<<"\n"; break;
            }
            if( p[3].z==6 && p[5].z==6 )
            {
                (*this).F(); (*this).L_(); (*this).D(); (*this).L(); (*this).D_(); (*this).F_(); cout<<"\n"; break;
            }

            if( p[7].z==6 && p[5].z==6 )
            {
                (*this).F(); (*this).L_(); (*this).D(); (*this).L(); (*this).D_(); (*this).F_(); cout<<"\n"; continue;
            }
            if( p[7].z==6 && p[3].z==6 )
            {
                (*this).R(); (*this).F(); (*this).D(); (*this).F_(); (*this).D_(); (*this).R_(); cout<<"\n"; continue;
            }
            if( p[1].z==6 && p[3].z==6 )
            {
                (*this).B_(); (*this).R(); (*this).D(); (*this).R_(); (*this).D_(); (*this).B(); cout<<"\n"; continue;
            }
            if( p[1].z==6 && p[5].z==6 )
            {
                (*this).L_(); (*this).B_(); (*this).D(); (*this).B(); (*this).D_(); (*this).L(); cout<<"\n"; continue;
            }
            (*this).F(); (*this).L_(); (*this).D(); (*this).L(); (*this).D_(); (*this).F_();
        }

        while(p[3].y!=2||p[1].x!=3||p[5].y!=4||p[7].x!=5)
        {
            if((p[3].y!=2)&&(p[1].x!=3)){(*this).B_();(*this).D();(*this).B();(*this).D();(*this).B_();(*this).D();(*this).D();(*this).B();(*this).D();  cout<<"\n"; }
            if((p[5].y!=4)&&(p[1].x!=3)){(*this).L_();(*this).D();(*this).L();(*this).D();(*this).L_();(*this).D();(*this).D();(*this).L();(*this).D();  cout<<"\n"; }
            if((p[5].y!=4)&&(p[7].x!=5)){(*this).F();(*this).D();(*this).F_();(*this).D();(*this).F();(*this).D();(*this).D();(*this).F_();(*this).D();  cout<<"\n"; }
            if((p[3].y!=2)&&(p[7].x!=5)){(*this).R();(*this).D();(*this).R_();(*this).D();(*this).R();(*this).D();(*this).D();(*this).R_();(*this).D();  cout<<"\n"; }
            if(p[3].y!=2&&p[5].y!=4)
            {
                (*this).R();(*this).D();(*this).R_();(*this).D();(*this).R();(*this).D();(*this).D();(*this).R_();(*this).D();
                (*this).F();(*this).D();(*this).F_();(*this).D();(*this).F();(*this).D();(*this).D();(*this).F_();(*this).D();
                (*this).R();(*this).D();(*this).R_();(*this).D();(*this).R();(*this).D();(*this).D();(*this).R_();(*this).D(); cout<<"\n";
            }
            if(p[1].x!=3&&p[7].x!=5)
            {
                (*this).B_();(*this).D();(*this).B();(*this).D();(*this).B_();(*this).D();(*this).D();(*this).B();(*this).D();
                (*this).R();(*this).D();(*this).R_();(*this).D();(*this).R();(*this).D();(*this).D();(*this).R_();(*this).D();
                (*this).B_();(*this).D();(*this).B();(*this).D();(*this).B_();(*this).D();(*this).D();(*this).B();(*this).D(); cout<<"\n";
            }
        }
        while(!C(p[0],3,2,6)||!C(p[2],3,4,6)||!C(p[8],5,4,6)||!C(p[6],5,2,6))
        {
            if(C(p[0],3,2,6)&&!C(p[2],3,4,6)&&!C(p[8],5,4,6)&&!C(p[6],5,2,6)){(*this).D();(*this).L_();(*this).D_();(*this).R_();(*this).D();(*this).L();(*this).D_();(*this).R(); cout<<"\n"; continue;}
            if(!C(p[0],3,2,6)&&C(p[2],3,4,6)&&!C(p[8],5,4,6)&&!C(p[6],5,2,6)){(*this).D();(*this).F();(*this).D_();(*this).B();(*this).D();(*this).F_();(*this).D_();(*this).B_(); cout<<"\n"; continue;}
            if(!C(p[0],3,2,6)&&!C(p[2],3,4,6)&&C(p[8],5,4,6)&&!C(p[6],5,2,6)){(*this).D();(*this).R();(*this).D_();(*this).L();(*this).D();(*this).R_();(*this).D_();(*this).L_(); cout<<"\n"; continue;}
            if(!C(p[0],3,2,6)&&!C(p[2],3,4,6)&&!C(p[8],5,4,6)&&C(p[6],5,2,6)){(*this).D();(*this).B_();(*this).D_();(*this).F_();(*this).D();(*this).B();(*this).D_();(*this).F(); cout<<"\n"; continue;}
            (*this).D();(*this).L_();(*this).D_();(*this).R_();(*this).D();(*this).L();(*this).D_();(*this).R();
        }
        if(p[6].z!=6)
        {
            while(p[6].z!=6||p[0].z!=6||p[8].z!=6||p[2].z!=6)
            {
                while(p[6].z!=6){(*this).B();(*this).U_();(*this).B_();(*this).U();(*this).B();(*this).U_();(*this).B_();(*this).U();cout<<"\n";}
                if(p[8].z!=6){(*this).D(); continue;}
                if(p[0].z!=6){(*this).D_(); continue;}
                if(p[2].z!=6){(*this).D(); (*this).D(); continue;}
            }
        }
        if(p[8].z!=6)
        {
            while(p[6].z!=6||p[0].z!=6||p[8].z!=6||p[2].z!=6)
            {
                while(p[8].z!=6){(*this).R_();(*this).U_();(*this).R();(*this).U();(*this).R_();(*this).U_();(*this).R();(*this).U(); cout<<"\n";}
                if(p[2].z!=6){(*this).D(); continue;}
                if(p[6].z!=6){(*this).D_(); continue;}\
                if(p[0].z!=6){(*this).D(); (*this).D(); continue;}
            }
        }
        if(p[2].z!=6)
        {
            while(p[2].z!=6||p[0].z!=6||p[8].z!=6||p[2].z!=6)
            {
                while(p[2].z!=6){(*this).F_();(*this).U_();(*this).F();(*this).U();(*this).F_();(*this).U_();(*this).F();(*this).U(); cout<<"\n";}
                if(p[2].z!=6){(*this).D(); continue;}
                if(p[6].z!=6){(*this).D_(); continue;}
                if(p[6].z!=6){(*this).D(); (*this).D(); continue;}
            }
        }
        if(p[0].z!=6)
        {
            while(p[6].z!=6||p[0].z!=6||p[8].z!=6||p[2].z!=6)
            {
                while(p[0].z!=6){(*this).L();(*this).U_();(*this).L_();(*this).U();(*this).L();(*this).U_();(*this).L_();(*this).U(); cout<<"\n";}
                if(p[2].z!=6){(*this).D(); continue;}
                if(p[6].z!=6){(*this).D_(); continue;}
                if(p[8].z!=6){(*this).D(); (*this).D(); continue;}
            }
        }
        while(p[3].y!=2) (*this).D();  cout<<"\n";
    }
    void solve()
    {
        cout << endl;
        cout<<"\nsolve first layer\n" << endl;
        solve_layer_first();
        cout << endl;
        cout<<"solve second layer\n" << endl;
        solve_layer_second();
        cout << endl;
        cout<<"\nsolve last layer\n" << endl;
        solve_layer_last();
    }
};


#endif //LAB8_CUBE_H
