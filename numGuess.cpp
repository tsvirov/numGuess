#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int minNum = 1, maxNum = 100;
    int tryNum = 0;
    int playerNum = rand() % (maxNum - minNum + 1) + minNum;
    string answer;

    cout << "\nЗагадайте число от 1 до 100\n\n";


    bool foundNum = false;

    do
    {
        itsNotTrueNum:
        tryNum++;
        cout << "Ваше число меньше, больше или равно " << playerNum << "? (less/more/is): ";
        cin >> answer;

        if (answer == "less")
        {
            maxNum = playerNum - 1;
            if (maxNum >= minNum)
            {
                playerNum = rand() % (maxNum - minNum + 1) + minNum;
                goto itsNotTrueNum;
            } else {goto error;}
        }
        else if (answer == "more")
        {
            minNum = playerNum + 1;
            if (maxNum >= minNum)
            {
                playerNum = rand() % (maxNum - minNum + 1) + minNum;
                goto itsNotTrueNum;
            } else {goto error;}
        }
        else if (answer == "is")
        {
            cout << "Компьютер угадал число " << playerNum << "!\n";
            cout << "Было потрачено "<< tryNum <<" пропыток!" << "\n";
            tryNum = 0;
            foundNum = true;
        }
        else
        {
            error:
            cout << "\nПопробуйте заново.\n";
                if(tryNum>=1){
                    tryNum --;
                }
            goto itsNotTrueNum;
        }

    } while (foundNum == false);

    return 0;
}