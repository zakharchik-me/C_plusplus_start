#include <iostream>
#include "cube.h"

int main()
{
    freopen("input.in","r",stdin);
//    freopen("output.out","w",stdout);

    cout << "Solving Rubik's Cube" << endl;
    cout<<"white: 1 orange: 2 green: 3 red: 4 blue: 5 yellow: 6 " << endl;

    CubeSolver solver;
    vector<vector<int>> tmp;
    for (auto v:tmp) {
        tmp.resize(3);
    }

    for(int i=0;i<6;i++)
    {
        for(int ii=0; ii < 3; ii++)
            for(int j=0;j<3;j++) cin>>tmp[ii][j];

        solver.enter_face(tmp);
    }

    if(solver.is_cube_wrong()) {
        cout << "Can't solve";
    } else {
        solver.solve();
    }

    return 0;
}
