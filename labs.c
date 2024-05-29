#include <stdio.h> 



int firstLab () 
{
int V, v1, v2;
printf("Введите объём бассейна (в литрах): ");
scanf("%d", &V);
printf("Введите скорость вытекания воды (в литрах в минуту): ");
scanf("%d", &v1);
printf("Введите скорость поступления воды (в литрах в минуту): ");
scanf("%d", &v2);
int time = V / (v1 - v2);
printf("Время, через которое бассейн станет пустым: %d минут\n",
time); return 0;
}


#include <stdio.h>



int secondLab ()
{
float s; // сумма ряда
float a; // очередной элемент ряда
float c, e; // числитель очередного элемента ряда
float b; // знаменатель очередного элемента ряда
int N; // число элементов ряда
int i; // номер очередного элемента ряда
// ввод параметров ряда
printf("N=");
scanf("%d", &N);
// начальное присваивание переменных
s = 0;
i = 0;
c = 1;
b = 1;
e = 1;
// цикл
while( i < N )
{
a = c / b;
s = s + a;
c = c * 3;
e = e + 3;
b = b * e;
i = i + 1;
}
// вывод результата
printf("s = %f\n", s);
return 0;
}



#include <stdio.h>



int thirdLab () {
    printf("Enter character stream: ");

    int counter = 0; // Счетчик слов
    int currentChar = getchar(); // Настоящий символ
    int flag = 0; // Есть ли в слове a (латинская маленькая)

    while (currentChar != EOF) { // Пока не закончится ввод (Ctrl+Z || Ctrl+D)
        currentChar = getchar(); // Получаем новый символ

        // Если символ является буквой а, то установить флаг и увеличить счетчик
        if (currentChar == 'a' && !flag) {
            counter++;
            flag = 1;
        }

        // Проверка, разделитель ли символ, и если да, то сбросить флаг
        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n') {
            flag = 0;
        }
    }
    // Цикл закончился, а значит и ввод закончился
    printf("Number of words with a: %d", counter); // Выводим результат
    return 0;
}

#include <stdio.h>

#define maxWord (4096)
#define maxString (4096)



int fourthLab () {
    printf("Enter character stream:\n");
    char wordBuffer[maxWord]; // Сюда формируется слово
    char stringBuffer[maxString]; // А сюда строка

    short wordLength = 0; // Считаем длину слова и строки
    short stringLength = 0;

    char currentChar = (char)getchar();
    char previousChar;

    while (currentChar != EOF) {
        previousChar = currentChar; // Считываем символ и сохраняем предыдущий
        currentChar = (char)getchar();

        if (!(previousChar == ' ' || previousChar == '.' || previousChar == ',' || previousChar == '\n')){
            // Слово не кончилось, записываем следущую букву
            wordBuffer[wordLength] = previousChar;
            wordLength++;
        }

        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n' || currentChar == EOF) {
            // Слово закончилось, проверяем, стоит ли добавлять его в строку
            if (wordBuffer[0] == wordBuffer[wordLength - 1]) {
                for (short i = 0; i < wordLength; ++i) {
                    stringBuffer[stringLength + i] = wordBuffer[i];
                }
                stringBuffer[stringLength + wordLength] = ';';
                stringBuffer[stringLength + wordLength + 1] = ' ';
                stringLength += wordLength + (short)2;
            }

            // Обнуляем слово
            wordBuffer[0] = '\0';
            wordLength = 0;

        }
    }

    printf("Resulting string: %s\n", stringBuffer);
    return 0;
}

#include <stdio.h>

#define ARRAY_SIZE (10)

int fifthLab () {
    int array[ARRAY_SIZE];
    printf("Enter %d integers for the array:\n", ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (scanf("%d", &array[i]) != 1) { printf("Error: Wrong value"); return 1;}
    }

    int min = 0;
    int max = ARRAY_SIZE - 1;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (array[i] < array[min]) {
            min = i;}
        if (array[i] > array[max]) {
            max = i;}
    }

    int start, end;
    if (min > max) {
        start = max;
        end = min;
    } else {
        start = min;
        end = max;
    }
    ++start;

    for (int i = start; i < end; ++i) {
        array[i] = 0;
    }

    printf("Modified Array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}

#include <stdio.h>

#define N (5)
#define K (10)

int matrix[N][K] = {{1, 2, 3, 4, 6, 6, 7, 8, 9, 10},
                    {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
                    {1, 2, 4, 8, 16, 32, 64, 128, 256, 512},
                    {2, 3,6, 74, 2, 5, 6,7, 87, 65},
                    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18}};

int sixthLab () {
    int delta;
    int currentDelta;
    int flag;

    for (short y = 0; y < N; ++y) {
        // Проходимся по строкам, для каждой берем изменение между 1 и 2 элементом
        delta = matrix[y][0] - matrix[y][1];
        flag = 1;

        for (short x = 2; x < K; ++x) {
            // Проходимя по всем остальным элементам
            currentDelta = matrix[y][x-1] - matrix[y][x];

            // Если изменение прогрессии не константа, то это не арифметическая прогрессия
            // Выходим из цикла, снимаем флаг
            if (currentDelta != delta) {
                flag = 0;
                break;
            }
        }

        if (flag) { printf("%u row is arithmetic progression\n", y+1);}
        else { printf("%u row isn't arithmetic progression\n", y+1);}
    }
    return 0;
}

#include <stdio.h>

int seventhLab () {
    long long int N;
    int K;

    printf("Enter a number:");
    if (scanf("%lld", &N) != 1) {
        printf("Wrong number!");
        return 1;}

    printf("Enter size of shift:");
    if (scanf("%d", &K) != 1) {
        printf("Wrong number!");
        return 1;
    }

    int bitCount = sizeof(long long int) * 8;

    // Подгоняем К, чтобы не выйти за пределы сегмента
    K %= bitCount;

    printf("Resulting number: %lld", ((N << K) | (N >> (bitCount - K))));

    return 0;
}
