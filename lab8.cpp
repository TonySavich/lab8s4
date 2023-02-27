#include <iostream>
#include <fstream>


int const N = 6;

struct deistr {
    int i;
    int path = 1000000;
    //  int neibor;

};

int main()
{
    int mas[N][N];


    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    in >> mas[i][j];
                }
            }


        }


    }
    in.close();


    int t, queu[N];

    t = -1;

    int v[N];
    deistr dop[N];
    for (int i = 0; i < N; i++) {
        v[i] = 0;
        dop[i].i = i;
    }


    int k;
    std::cin >> k;
    std::cout << std::endl;
    k = k - 1;
    dop[k].path = 0;

    int och[N];
    int rr = -1;
    int y = 0;
    rr++;
    och[rr] = k;



    while (y != N) {



        for (int i = 0; i < N; i++) {
            if (i != k) {
                if (mas[k][i] != 0) {
                    if (v[i] == 0) {
                        t++;
                        queu[t] = i;
                        bool f = false;
                        for (int j = 0; j <= rr; j++) {
                            if (och[j] == i) {
                                f = true;
                            }
                        }
                        if (f == false) {
                            rr++;
                            och[rr] = i;
                        }
                    }

                }
            }
        }


        for (int i = 0; i < t + 1; i++) {
            if (dop[k].path + mas[dop[k].i][queu[i]] < dop[queu[i]].path) {
                dop[queu[i]].path = dop[k].path + mas[dop[k].i][queu[i]];
                //      dop[queu[i]].neibor = dop[k].i;
            }
        }


        v[dop[k].i] = 1;
        y++;

       for (int i = y; i <= rr; i++) {
            for (int j = i + 1; j <= rr; j++) {
                if (dop[och[i]].path > dop[och[j]].path) {
                    std::swap(och[i], och[j]);
                }
            
            }

        }

        k = och[y];

        for (int i = 0; i <= t; i++) {
            queu[i] = 0;
        }
        t = -1;


    }

    for (int i = 0; i < N; i++) {
        std::cout << dop[i].i + 1 << " --- " << dop[i].path << std::endl;

    }

}
