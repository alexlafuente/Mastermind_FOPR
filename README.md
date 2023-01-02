# Mastermind

Regles del joc:

El joc es desenvolupa en un tauler amb dos fitxes de dues mides diferents:

• petites: Són de color blanc i negre i serveixen per indicar els errors i encerts.
• grans: S’utilitzen 9 fitxes de 9 colors diferents per generar el codi ocult i intentar
         esbrinar-lo.
           
Un dels jugadors (jugador A) escull 4 fitxes grans de colors i que formarà el codi secret
ocult. L’altre jugador (jugador B) ha d’esbrinar el codi secret. Primerament, agafa 4
fitxes de colors i planteja una possibilitat. El jugador A ha de respondre amb les fitxes
petites. La resposta estarà formada com a màxim per 4 fitxes petites. Posarà una fitxa
negra quan la fitxa de color està ben col·locada i una fitxa petita blanca quan el color
apareix al codi ocult, però està mal col·locat. Si una fitxa gran no està al codi secret
llavors no es posa cap fitxa.

El joc acaba quan s’encerta la combinació (és a dir, quan s’aconsegueix una combinació amb
quatre fitxes negres), o bé s’esgota el tauler (es tenen 10 intents).
Per conveniència, codifiquem els colors amb els següents nombres:

Blau: 1
Groc: 2
Vermell: 3
Verd: 4
Marró: 5
Rosa: 6
Violeta: 7
Taronja: 8
Cian: 9

Les fitxes per marcar si una resposta és correcta o no les codificarem de la següent
manera:

• Les fitxes Negres es representen amb el caràcter ’X’.
• Les fitxes Blanques amb el caràcter ’O’.
