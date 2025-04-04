# MEPHI C Training

Этот репозиторий содержит набор тренировочных задачек на языке C.

## Структура проекта

- `taskN/` — директория задачи (например, `task1/`, `task2/` и т.д.)
- `armstrong/` — пример директории переиспользуемой библиотеки
- `archives/` — архивы с задачей и необходимыми библиотеками для возможности пересылки и последующей сборки, создаются с попомощью скрипта `package.sh`

Каждая задача (`taskN`) содержит свой `README.md` с инструкциями по сборке и запуску.

## Сборка

Для каждой задачи используется CMake. Перейдите в нужную директорию задачи:

```bash
cd task1
mkdir -p build && cd build
cmake ..
make
./task1
```

## Упаковка задания

Для создания архива используйте скрипт `package.sh`:

```bash
./package.sh task1 armstrong
```

Архив будет создан в `archives/task1.zip` со структурой:

```
mephi-task1/
├── task1/
├── armstrong/
```
