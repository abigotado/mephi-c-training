# Задача №1 — Проверка числа Армстронга

## Структура архива

Архив для задачи содержит следующие директории:

```
mephi-task1/
├── task1/
└── libs/
    └── armstrong/
```

## Инструкции по сборке и запуску

1. Убедитесь, что установлен CMake (`cmake --version`) и компилятор `gcc` или `clang`.
2. Из корневой директории `mephi-task1` выполните следующие команды:

```bash
cd task1
mkdir -p build && cd build
cmake ..
make
```

3. Запустите программу:

```bash
./task1
```

## Пример использования

```bash
Введите число: 153
Проанализированное число является числом Армстронга.
Сумма цифр: 9
```

## Проверка на утечки памяти

Для проверки корректности работы с памятью используйте valgrind:

```bash
valgrind --leak-check=full ./task1
```
