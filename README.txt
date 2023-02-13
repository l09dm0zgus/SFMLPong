
1.Код написано повністю на С++.
2.Проєкт повністю написаний в стилі ООП.
3.Використовується STL.Наприклад розумний вказівник і вектор  в src/gameobject/GameObject.cpp або алгоритм std::copy  в  src/gameobject/Scene.cpp або алгоритм std::for_each  і лямда функція  в src/window/Window.cpp.
4.Код було форматовано clang-format.
5.Була використана зовнішня бібліотека SFML і була підключена  в cmake файлі.
6.Логіка гри і відображення розділена.Є клас GameObject в якому є методи start і update , в них пишеться логіка гри.
відображення гри в класі Window в методі render().
7.Були використованні патерни Component (src/components/IComponent.hpp , src/gameobject/GameObject.cpp)
і паттерн Observer в src/gameobject/ScoreObserver.cpp
8.Щоб запустити проєкт:
Linux: зайти в директорію builds/Linux64 і запустити файл Pong
