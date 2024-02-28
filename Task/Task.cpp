#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int a, b, magicNum, userNum;
    int userChoice, userLives, userPoints, guessed;
    userPoints = 0;
    guessed = 0;

    cout << "Добро пожаловать в игру!\n";
    cout << "Вы будуте последовательно проходить по уровням (если сможете победить):\n";
    cout << "1 lvl: Загадочных цифр [1..10]\n";
    cout << "2 lvl: Загадочных цифр [10..100]\n";
    cout << "Начинаем? \n" << "1 = ДА!\n" << "2 = Нет..\n" << endl;
    cin >> userChoice;
    if (userChoice == 1)
    {
        do
        {
            cout << "Приветствуем на первом уровне игры!\n";
            a = 1;
            b = 10;
            userLives = (b - a + 1) / 2;

            for (int i = 0; i < userLives; i++)
            {
                cout << "Компьютер загадывает число...\n";
                Sleep(300);
                magicNum = a + rand() % (b - a);
                cout << "Загаданное число готово! ХАХ, попробуй его угадать!\n" << magicNum << endl;
                cout << "Что Игрок сейчас имеет: ";
                cout << userLives << " Жизней.\n";
                cout << "Твоя цифра?\n";
                cin >> userNum;
                if (userNum == magicNum)
                {
                    cout << "Ты отгодал! ХАх.. Но, только на этот раз...\n";
                    guessed = guessed + 1;
                    userLives = userLives + 1;
                }
                else
                {
                    cout << "ХАХАХ! Ты проиграл и потерял 1 жизнь!" << endl;
                    userLives--;
                }
                if (guessed == 3)
                {
                    cout << "Ты победил на первом lvl! Неплохо чел!" << endl;
                    break;
                }
            }
        } while ((userLives != 0) || (guessed == 3));
        if (userLives == 0)
        {
            cout << "Ты даже до второго раунда не добрался....АХАХАХАХАХ" << endl;
        }

        while (guessed == 3)
        {
            userPoints = userLives * 5;
            cout << userPoints << " очков у тебя друг!" << endl;
            cout << "Продолжим во втором раунде? \n" << "1 = ДА!\n" << "2 = Нет..\n" << endl;
            cin >> userChoice;
            if (userChoice == 1)
            {
                a = 10;
                b = 100;
                userLives = userLives + ((b - a + 1) / 4);
                cout << "Компьютер снова загадывает...\n";
                Sleep(300);
                magicNum = a + rand() % (b - a);

                for (int i = 0; i < userLives; i++)
                {
                    cout << "Компьютер загадывает число...\n";
                    Sleep(300);
                    magicNum = a + rand() % (b - a);
                    cout << "Загаданное число готово! ХАХ, попробуй его угадать!\n" << magicNum << endl;
                    cout << "Что Игрок сейчас имеет: ";
                    cout << userLives << " Жизней.\n";
                    cout << "Твоя цифра?\n";
                    cin >> userNum;
                    if (userNum == magicNum)
                    {
                        cout << "Ты отгодал! БОЖЕ, ДА ЭТО ЖЕ ПОБЕДА!!!!\n";
                        guessed = guessed + 1;
                        userLives = userLives + 1;
                        userPoints = userPoints + (userLives * 10);
                        cout << userPoints << " очков у тебя друг!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "ХАХАХ! Ты проиграл и потерял 1 жизнь!";
                        userLives--;
                    }
                    if (userLives == 0)
                    {
                        cout << "Ну, ты проиграл.... В следующий раз повезет))" << endl;
                    }
                }
            }
            else
            {
                cout << "На этом тогда и закончим...";
            }

        }

    }
    else
    {
        cout << "Ну, тогда не поиграем получается..." << endl;
    }
    return 0;
}
