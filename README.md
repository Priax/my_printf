# my_printf

Un projet perso en C pour recréer une version basique de printf.
L’objectif principal est d’apprendre la gestion des formats, des flags, et des arguments variadiques.

# Fonctionnalités

    Support des flags classiques : %c, %s, %d, %i, %f, %b, %X, %x, %o, %u, %%.

    Gestion simple de la précision avec . (ex : %.3f).

    Architecture modulaire avec table de flags et fonctions dédiées.

    Écriture directe sur la sortie standard.

# Compilation

```sh
$> make
$> ./my_printf
$> make fclean
```

# Utilisation

my_printf("Hello %.2s, number %d, hex %x, float: %f\n", "world", 42, 255, 126.1234567);

# Limitations

    Pas de gestion avancée des flags (padding, alignement, etc.).

    Précision limitée, surtout pour les floats.

    Fonctionnalités minimales, à étendre selon besoins.
