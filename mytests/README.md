


| Flag \ Spéc. | `c` (caractère)        | `s` (chaîne)               | `p` (pointeur)                       | `d` / `i` (entier signé)               | `u` (entier non signé)    | `x` (hex minuscule)                   | `X` (hex majuscule)                   |
|--------------|------------------------|----------------------------|---------------------------------------|----------------------------------------|---------------------------|----------------------------------------|----------------------------------------|
| `#`          | Sans effet            | Sans effet                | Ajoute `0x` devant l’adresse         | Sans effet                             | Sans effet                | Ajoute `0x` devant les nombres ≠ 0    | Ajoute `0X` devant les nombres ≠ 0    |
| `0`          | Sans effet            | Sans effet                | Remplit de `0` à gauche (selon width) | Ajoute des `0` pour remplir la largeur (ignore si `-` présent) | Idem                  | Remplit de `0` à gauche               | Remplit de `0` à gauche               |
| `-`          | Alignement à gauche   | Alignement à gauche       | Alignement à gauche (largeur minimale) | Alignement à gauche                    | Alignement à gauche       | Alignement à gauche                   | Alignement à gauche                   |
| `+`          | Sans effet            | Sans effet                | Sans effet                           | Ajoute toujours le signe (+ ou -)      | Sans effet                | Sans effet                            | Sans effet                            |
| `espace`     | Sans effet            | Sans effet                | Sans effet                           | Ajoute un espace avant les nombres positifs (si `+` non utilisé) | Sans effet            | Sans effet                            | Sans effet                            |

### Détails des flags :
- **`#` :**  
  Utilisé principalement avec les spécificateurs hexadécimaux (`x`, `X`) et les pointeurs (`p`).  
  - Pour `x`/`X`, ajoute un préfixe (`0x` ou `0X`) si le nombre est différent de 0.
  - Pour `p`, garantit que l’adresse contient `0x`.

- **`0` :**  
  Remplit de `0` à gauche pour compléter la largeur minimale spécifiée, sauf si le flag `-` est présent (dans ce cas, il est ignoré).

- **`-` :**  
  Force l’alignement à gauche, en complétant avec des espaces si nécessaire.

- **`+` :**  
  Force l’affichage du signe (`+` ou `-`) pour les nombres entiers signés (`d`, `i`).

- **`espace` :**  
  Ajoute un espace avant les nombres positifs pour les spécificateurs `d` et `i`, sauf si le flag `+` est utilisé.

