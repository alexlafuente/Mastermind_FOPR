
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)

[![Logo](https://camo.githubusercontent.com/824ab59f0f7eff5585ea26cb01600b956575c85b87824e362738a74cd52c0c06/68747470733a2f2f7777772e7570632e6564752f636f6d756e69636163696f2f63612f6964656e74697461742f646573636172726567612d6172786975732d677261666963732f666974786572732d6d617263612d7072696e636970616c2f7570632d706f73697469752d70333030352e706e67)](https://www.upc.edu/ca)

# Mastermind



Aquest joc conforma la meva pràctica de l'assignatura de Fonaments de la Programació 
a l'EPSEVG (UPC).

## Regles del joc

El joc es desenvolupa en un tauler amb dos fitxes de dues mides diferents:

- Petites: Són de color blanc i negre. Serveixen per indicar els errors i encerts.

- Grans: S’utilitzen 9 fitxes de 9 colors diferents per generar el codi ocult, i intentar esbrinar-lo.
           
Un dels jugadors (jugador A) escull 4 fitxes grans de colors que formarà el codi secret ocult. L’altre jugador (jugador B) ha d’esbrinar el codi secret.

Primerament, el jugador B agafa 4 fitxes de colors i planteja una possibilitat. El jugador A ha de respondre amb les fitxes petites. La resposta estarà formada per 4 fitxes petites. El jugador A posarà una fitxa negra quan la fitxa de color existeixi al codi ocult i estigui ben col·locada, i posarà una fitxa petita blanca quan el la fitxa de color aparegui al codi ocult, però estigui mal col·locada. Si una fitxa gran no està al codi secret, el jugador a no posarà cap fitxa.

El joc acaba quan s’encerta la combinació (és a dir, quan el jugador B aconsegueix una combinació amb quatre fitxes negres), o quan s’omple tot el tauler (hi ha 10 intents).

Per conveniència, els colors estan codificats amb els següents nombres:

- Blau: **1**

- Groc: **2**

- Vermell: **3**

- Verd: **4**

- Marró: **5**

- Rosa: **6**

- Violeta: **7**

- Taronja: **8**

- Cian: **9**

Les fitxes utilitzades per marcar si una resposta és correcta o no, estan codificades de la següent manera:

- Les fitxes negres es representen amb el caràcter ’**X**’

- Les fitxes blanques amb el caràcter ’**O**’

## Resum

El joc comença demanant al jugador A, un codi de 4 xifres (entre l'1 i el 9), que no es poden repetir. A continuació, el jugador B té 10 intents per tractar d'endevinar el codi. Després de cada intent, es mostrarà la correspondència entre els nombres de la jugada i el codi secret:

- Si el nombre apareix al codi i està a la posició correcta, es mostrarà una ’**X**’
- Si el nombre apareix al codi, però està en una posició incorrecta, es mostrarà una ’**O**’
- Si el nombre no apareix al codi, es mostrarà un ’**-**’
