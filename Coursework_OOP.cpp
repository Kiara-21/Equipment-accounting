#include <iostream>

using namespace std;


class System_unit // Клас "Системный блок"
{
public:
    string CPU; // Модель процессора
    double Clock_frequency; // Тактовая часота
    double Hard_drive_size; // Емкость жесткого диска
    string CD_drive; // Модель CD-привода
    double Price_S; // Стоимость

    System_unit() // Конструктор класса
    {
            cout << "Введіть модель процессору\n";           
            cin >> CPU;                               
            cout << "Введіть тактову частоту\n";         
            cin >> Clock_frequency;                    
            cout << "Введіть ємність жорсткого диска\n";          
            cin >> Hard_drive_size;                    
            cout << "Введіть модель СD-приводу\n";            
            cin >> CD_drive;                           
            cout << "Введіть вартість\n";                    
            cin >> Price_S;                            
    }
};


class Monitor // Класс "Монитор"
{
public:
    double Diagonal; // Диагональ
    string Screen_resolution; // Разрешение экрана
    double Price_M; // Стоимость

    Monitor() // Конструктор класса
    {
        cout << "Введіть діагональ\n";                    
        cin >> Diagonal;                              
        cout << "Введіть роздільну здатність екрану\n";           
        cin >> Screen_resolution;                    
        cout << "Введіть вартість\n";                       
        cin >> Price_M;                                
    }
};

class Keyboard // Класс "Клавиатура"
{
public:
    string K_type; // Модель клавиатуры
    int Number_of_keys; // Количество клавиш
    double Price_K; // Стоимость

    Keyboard() // Конструктор класса
    {
        cout << "Введіть модель клавіатури\n";             
        cin >> K_type;                                
        cout << "Введіть кількість клавіш\n";              
        cin >> Number_of_keys;                        
        cout << "Введіть вартість\n";                      
        cin >> Price_K;                               
    }
};

class Mouse // Класс "Мышь"
{
public:
    string M_type; // Тип мыши
    int Number_of_buttons; // Количество кнопок
    double Price_Ms; // Стоимость

    Mouse()
    {
        cout << "Введіть модель миші\n";                 
        cin >> M_type;                                
        cout << "Введіть кількість кнопок\n";           
        cin >> Number_of_buttons;                     
        cout << "Введіть вартість\n";                       
        cin >> Price_Ms;                              
    }
};


class Computer: System_unit, Monitor, Keyboard, Mouse // Класс "Компьютер". Наследуеться от всех вышеописанных классов
{
public:

    double Price; // Стоимость

    Computer()
    {
        Price = Price_S + Price_M + Price_K + Price_Ms; // Подсчет итоговой стоимости компьютера
    }

    void GetInfo() // Функция для вывода информации про объект класса
    {
        cout << "Модель процессору - " << CPU << "\n";
        cout << "Ємність жорсткого диска - " << Hard_drive_size << "\n";
        cout << "Модель CD-приводу - " << CD_drive << "\n";
        cout << "Такстова частота - " << Clock_frequency << "\n";
        cout << "Вартість системного блоку - " << Price_S << "\n";
        cout << "Діагональ монітору - " << Diagonal << "\n";
        cout << "Роздільна здатність екрану - " << Screen_resolution << "\n";
        cout << "Вартість монітору - " << Price_M << "\n";
        cout << "Модель клавіатури - " << K_type << "\n";
        cout << "Кількість клавіш - " << Number_of_keys << "\n";
        cout << "Вартість клавіатури - " << Price_K << "\n";
        cout << "Модель миші - " << M_type << "\n";
        cout << "Кількість кнопок миші - " << Number_of_buttons << "\n";
        cout << "Вартість миші - " << Price_Ms << "\n";
        cout << "******************************";
    }

    void GetPrice() // Функция вывода стоимости компьютера
    {
        cout << "Загальна вартість = " << Price <<"\n"; // Вывод стоимости
    }
};

class Computer_class // Класс "Компьютерный класс"
{
public:

    double All_price; // Итоговая стоимость
    Computer arr[3]; // Массив объектов класса "Компьютер"

    Computer_class()
    {   double all = 0;
        for (int i = 0; i < 3; i++)
        {
            all = all + arr[i].Price; // Подсчет итоговой стоимости
        }
         All_price = all; 
    }

    void GetAllInfo() // Функция для получения информации про все компьютеры в классе
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Комп'ютер №" << i <<":\n"; // Вывод номера компьютера
            arr[i].GetInfo(); // Вызов функции для вывода информации про компьютер
        }
    }

    void GetOnePrice() // Функция для вывода стоимости компьютеров по отдельности
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Комп'ютер №" << i << ":\n"; // Вывод номера компьютера
            arr[i].GetPrice(); // Вызов функции для вывода стоимости одного компьютера
        }
    }

    void GetAllPrice() // Функция для вывода суммарной стоимости оборудования компьютерного класса 
    {
        cout << "Загальна вартість обладнання класу - " << All_price <<"\n"; // Вывод суммарной стоимости всех компьютеров
    }
};

int main()
{
    cout << "Доброго дня! Ця програма допоможе скласти базу комп'ютерів у комп'ютерному класі\n";
    cout << "Введіть компоненти комп'ютерів:\n";
    Computer_class c_class; // Создание объекта класса "Компьютерный класс"
    cout << "-------------------------------"; 
    cout << "Ви ввели наступну інформацію:\n";
    c_class.GetAllInfo(); // Вывод информации про все компьютеры
    cout << "-------------------------------";
    cout << "Загальна вартість одного комп'ютера:\n";
    c_class.GetOnePrice(); // Вывод стоимости компьютеров по одному
    cout << "-------------------------------";
    cout << "Підрахунок загальної вартості обладнання у класі:\n";
    c_class.GetAllPrice(); // Вывод суммарной стоимости оборудования в классе
    cout << "-------------------------------";
    cout << "Кінець програми"; // Конец программы 
}
