#include "mainClasses.cpp"

int main()
{
    //freopen("input.txt","r",stdin);
    string user1, user2;
    int roww, columnn;
    cout << "Name of First player : ";
    getline(cin, user1);
    cout << "\nName of Second player : ";
    getline(cin, user2);
    GameBoard game1;
    game1.setName1(user1);
    game1.setName2(user2);
    for (int i = 1; i <=8; i++)
    {
        cout << "*****Player 1 turn*****" << endl;
        cout << "Enter the row you wish to place your X : ";
        cin >> roww;
        cout << "Enter the column you wish to place your X : ";
        cin >> columnn;
        game1.setCharX(roww, columnn);
        if (i > 3)
        {
            if ( game1.fourInRow() == 1 || game1.fourInColumn()==1 || game1.fourInDiagonal()==1)
            {
                game1.printMatrix();
                game1.printInfo(1);
                exit(0);
            }
            else if (game1.fourInRow() == 2 || game1.fourInColumn()==2 || game1.fourInDiagonal()==2)
            {
                game1.printMatrix();
                game1.printInfo(2);
                exit(0);
            }
        }
        cout << "*****Player 2 turn*****" << endl;
        cout << "Enter the row you wish to place your O : ";
        cin >> roww;
        cout << "Enter the column you wish to place your O : ";
        cin >> columnn;
        game1.setCharO(roww, columnn);
        if (i > 3)
        {
            if (game1.fourInRow() == 1 || game1.fourInColumn()==1 || game1.fourInDiagonal()==1)
            {
                game1.printMatrix();
                game1.printInfo(1);
                exit(0);
            }
            else if (game1.fourInRow() == 2 || game1.fourInColumn()==2 || game1.fourInDiagonal()==2)
            {
                game1.printMatrix();
                game1.printInfo(2);
                exit(0);
            }
        }
    }

    game1.printInfo(3);
    return 0;
}