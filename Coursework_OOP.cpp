#include <iostream>

using namespace std;


class System_unit // Клас "Системный блок"
{
public:
    System_unit() // Конструктор класса
    {
            cout << "Введіть модель процессору\n";           
            cin >> cpu;                               
            cout << "Введіть тактову частоту\n";         
            cin >> clock_frequency;                    
            cout << "Введіть ємність жорсткого диска\n";          
            cin >> hard_drive_size;                    
            cout << "Введіть модель СD-приводу\n";            
            cin >> cd_drive;                           
            cout << "Введіть вартість\n";                    
            cin >> price_s;                            
    }
    friend class Computer;
private:
    string cpu; // Модель процессора
    double clock_frequency; // Тактовая часота
    double hard_drive_size; // Емкость жесткого диска
    string cd_drive; // Модель CD-привода
    double price_s; // Стоимость
};


class Monitor // Класс "Монитор"
{
public:
    Monitor() // Конструктор класса
    {
        cout << "Введіть діагональ\n";                    
        cin >> diagonal;                              
        cout << "Введіть роздільну здатність екрану\n";           
        cin >> screen_resolution;                    
        cout << "Введіть вартість\n";                       
        cin >> price_m;                                
    }
    friend class Computer;
private:
    double diagonal; // Диагональ
    string screen_resolution; // Разрешение экрана
    double price_m; // Стоимость
};

class Keyboard // Класс "Клавиатура"
{
public:
    Keyboard() // Конструктор класса
    {
        cout << "Введіть модель клавіатури\n";             
        cin >> k_type;                                
        cout << "Введіть кількість клавіш\n";              
        cin >> number_of_keys;                        
        cout << "Введіть вартість\n";                      
        cin >> price_k;                               
    }
    friend class Computer;
private:
    string k_type; // Модель клавиатуры
    int number_of_keys; // Количество клавиш
    double price_k; // Стоимость
};

class Mouse // Класс "Мышь"
{
public:
    Mouse()
    {
        cout << "Введіть модель миші\n";                 
        cin >> m_type;                                
        cout << "Введіть кількість кнопок\n";           
        cin >> number_of_buttons;                     
        cout << "Введіть вартість\n";                       
        cin >> price_ms;                              
    }
    friend class Computer;
private:
    string m_type; // Тип мыши
    int number_of_buttons; // Количество кнопок
    double price_ms; // Стоимость
};


class Computer: System_unit, Monitor, Keyboard, Mouse // Класс "Компьютер". Наследуеться от всех вышеописанных классов
{
public:
    Computer()
    {
        price = price_s + price_m + price_k + price_ms; // Подсчет итоговой стоимости компьютера
    }
    void GetInfo() // Функция для вывода информации про объект класса
    {
        cout << "Модель процессору - " << cpu << "\n";
        cout << "Ємність жорсткого диска - " << hard_drive_size << "\n";
        cout << "Модель CD-приводу - " << cd_drive << "\n";
        cout << "Такстова частота - " << clock_frequency << "\n";
        cout << "Вартість системного блоку - " << price_s << "\n";
        cout << "Діагональ монітору - " << diagonal << "\n";
        cout << "Роздільна здатність екрану - " << screen_resolution << "\n";
        cout << "Вартість монітору - " << price_m << "\n";
        cout << "Модель клавіатури - " << k_type << "\n";
        cout << "Кількість клавіш - " << number_of_keys << "\n";
        cout << "Вартість клавіатури - " << price_k << "\n";
        cout << "Модель миші - " << m_type << "\n";
        cout << "Кількість кнопок миші - " << number_of_buttons << "\n";
        cout << "Вартість миші - " << price_ms << "\n";
        cout << "******************************";
    }
    void GetPrice() // Функция вывода стоимости компьютера
    {
        cout << "Загальна вартість = " << price <<"\n"; // Вывод стоимости
    }
    friend class Computer_class;
private:
    double price;
};

class Computer_class // Класс "Компьютерный класс"
{
public:
    Computer_class()
    {   double all = 0;
        for (int i = 0; i < 3; i++)
        {
            all = all + arr[i].price; // Подсчет итоговой стоимости
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
private:
    double All_price; // Итоговая стоимость
    Computer arr[3]; // Массив объектов класса "Компьютер"
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
