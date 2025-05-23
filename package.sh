#!/bin/bash

set -e

if [ "$#" -lt 1 ]; then
  echo "❌ Использование: $0 <имя_основной_папки> [доп_папка1 доп_папка2 ...]"
  exit 1
fi

TASK_NAME="$1"
shift

ARCHIVE_DIR="archives/mephi-${TASK_NAME}"
ZIP_NAME="archives/${TASK_NAME}.zip"

# Очистка старой директории архива
rm -rf "$ARCHIVE_DIR" "$ZIP_NAME"
mkdir -p "$ARCHIVE_DIR"

# Копируем нужные директории
echo "→ Копируем $TASK_NAME..."
rsync -av --exclude 'build' "$TASK_NAME" "$ARCHIVE_DIR/"

# Создаем директорию libs
mkdir -p "$ARCHIVE_DIR/libs"

for folder in "$@"; do
  echo "→ Копируем $folder..."
  # Проверяем наличие папки в libs
  if [ -d "libs/$folder" ]; then
    rsync -av --exclude 'build' "libs/$folder" "$ARCHIVE_DIR/libs/"
  # Проверяем наличие папки в корне
  elif [ -d "$folder" ]; then
    rsync -av --exclude 'build' "$folder" "$ARCHIVE_DIR/"
  else
    echo "⚠️  Предупреждение: папка $folder не найдена ни в libs/, ни в корне"
  fi
done

# Упаковка
echo "→ Упаковываем в $ZIP_NAME..."
cd archives
zip -r "${TASK_NAME}.zip" "mephi-${TASK_NAME}"
cd ..

rm -rf "$ARCHIVE_DIR"

echo "✅ Архив создан: $ZIP_NAME"