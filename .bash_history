git remote https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming
git remote add  https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming
git remote add https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming
git remote add origin https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming.git
git remote remove origin
git remote add origin https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming.git
git config --global user.name "Alanoud Aloraydi"
git config --global user.email "alanoudkh16@gmail.com"
git remote add origin https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming.git
git remote https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming
git remote remove origin
git remote add origin https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming.git
ls
git init
git remote add origin https://github.com/Alanoud-Aloraydi/holbertonschool-low_level_programming.git
cd holbertonschool-low_level_programming
ls
git pull origin main --allow-unrelated-histories
ls
git checkout main
git pull
git checkout -b create-array
mkdir malloc_free
cat > malloc_free/README.md << 'EOF'
Made by Alanoud Aloraydi
EOF

cat > malloc_free/0-create_array.c << 'EOF'
#include "main.h"
#include <stdlib.h>

char *create_array(unsigned int size, char c)
{
    char *arr;
    unsigned int i;

    if (size == 0)
        return (NULL);

    arr = malloc(size);
    if (arr == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        arr[i] = c;

    return (arr);
}
EOF

git add .
git commit -m "Create function to initialize char array with given value"
git push --set-upstream origin create-array
git config --global credential.helper store
