
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![Build passing](https://app.travis-ci.com/travis-ci/travis-web.svg?branch=master)]()

![Logo](https://camo.githubusercontent.com/824ab59f0f7eff5585ea26cb01600b956575c85b87824e362738a74cd52c0c06/68747470733a2f2f7777772e7570632e6564752f636f6d756e69636163696f2f63612f6964656e74697461742f646573636172726567612d6172786975732d677261666963732f666974786572732d6d617263612d7072696e636970616c2f7570632d706f73697469752d70333030352e706e67)

# Mastermind



Aquest joc conforma la meva pràctica de l'assignatura de Fonaments de la Programació 
a l'EPSEVG (UPC).

## Regles del joc

El joc es desenvolupa en un tauler amb dos fitxes de dues mides diferents:

- petites: Són de color blanc i negre i serveixen per indicar els errors i encerts.

- grans: S’utilitzen 9 fitxes de 9 colors diferents per generar el codi ocult i intentar esbrinar-lo.
           
Un dels jugadors (jugador A) escull 4 fitxes grans de colors que formarà el codi secret ocult. L’altre jugador (jugador B) ha d’esbrinar el codi secret.

Primerament, el jugador B agafa 4 fitxes de colors i planteja una possibilitat. El jugador A ha de respondre amb les fitxes petites. La resposta estarà formada com a màxim per 4 fitxes petites. Posarà una fitxa negra quan la fitxa de color estigui ben col·locada, i una fitxa petita blanca quan el color aparegui al codi ocult, però estigui mal col·locat. Si una fitxa gran no està al codi secret llavors no es posa cap fitxa.

El joc acaba quan s’encerta la combinació (és a dir, quan s’aconsegueix una combinació amb quatre fitxes negres), o bé s’esgota el tauler (es tenen 10 intents).

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

Les fitxes per marcar si una resposta és correcta o no, les codifiquem de la següent manera:

- Les fitxes negres es representen amb el caràcter ’**X**’.

- Les fitxes blanques amb el caràcter ’**O**’.
