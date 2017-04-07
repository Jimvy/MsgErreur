.. -*- coding: utf-8 -*-
.. Copyright |copy| 2017 by `Olivier Bonaventure <http://perso.uclouvain.be/olivier.bonaventure>`_
.. Ce fichier est distribué sous une licence `creative commons <http://creativecommons.org/licenses/by-sa/3.0/>`_

Erreurs retournées par gcc_
===========================

Ce document reprend les principaux messages d'erreurs retournés par le compilateur gcc_ avec
un exemple simple qui illustre chaque message d'erreur et comment il peut être corrigé.

Sauf indication contraire, gcc_ est lancé avec les arguments ``-Wall -Werror -std=c99``.


:index:`control reaches end of non-void function (gcc)`
-------------------------------------------------------
.. sectionauthor:: Olivier Bonaventure 


.. literalinclude:: src/noreturn/noreturn.c
   :language: c

Lorsque ce programme est compilé en utilisant gcc_, il retourne l'erreur 
:index:`control reaches end of non-void function (gcc)`. Cette erreur indique que l'étudiant a
oublié de retourner la valeur de retour de la fonction ``f`` (dans ce cas, la valeur
attendue est de type ``int``).

.. literalinclude:: src/noreturn/noreturn.gcc
   :language: console


:index: `variably modified array at file scope`
-----------------------------------------------
.. sectionauthor:: Jean-Martin Vlaeminck

.. literalinclude:: src/variably_modified/variably_modified.c
   :language: c

Lorsque ce programme est compilé en utilisant gcc_, il retourne le warning
:index:`variably modified 'tableau' at file scope`. Cette erreur provient de l'initialisation
du tableau : la taille a été spécifiée avec un entier constant ``taille`` au lieu d'une
déclaration avec la macro ``#define``. En remplaçant la ligne 2 par

.. code-block:: c

   #define taille 1000

le code compile sans erreur ou warning. La raison de cette erreur est que le mot-clé ``const``
ne signifie pas que la variable est constante, mais qu'elle n'est accessible qu'en lecture
(read-only). Il reste tout à fait possible de modifier cette variable par d'autres moyens, et
le compilateur interdit donc d'utiliser une telle constante pouvant varier. Un ``#define`` ou
une énumération définit par contre une vraie constante. A noter que cette erreur n'arrive pas
dans le cas d'une variable locale, et que C++ autorise une telle construction.

.. literalinclude:: src/variably_modified/variably_modified.gcc
   :language: console

:index: `variable-sized object may not be initialized`
------------------------------------------------------

.. literalinclude:: src/array_initialization/array_initialization.c
   :language: c

.. en utilisant const int au lieu de define, et en mettant la liste d'initialisation.

Lorsque ce programme est compilé en utilisant gcc_, il renvoie l'erreur truc. Cette erreur
provient de la liste d'initialisation du tableau, qui n'est pas autorisée si la taille du
tableau est définie par une variable. On peut éliminer cette erreur en retirant la liste
d'initialisation et en initialisant soi-même, ou en remplaçant la taille par une déclaration
avec ``#define``.

:index: `data definition has no type or storage class`
------------------------------------------------------

.. L'exemple avec des tableaux où on met d'autres codes venant d'un autre tableau.

Lorsque ce programme est compilé avec gcc_, il renvoie l'erreur :index: `data definition has no type or storage class`. L'origine de cette erreur est l'affectation présente à la ligne truc. Dans un programme C, il est interdit d'avoir du code en dehors d'aucune fonction ; seules des déclarations de fonction, de structure ou de variables peuvent avoir lieu. Pour résoudre le problème, il suffit de déplacer les lignes incriminées vers l'intérieur de la fonction ``main()``.


