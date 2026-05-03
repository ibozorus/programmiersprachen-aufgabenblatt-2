Aufgabe 2.9
# Sollte diese Methode als const deklariert werden?
Ja, weil die circumference() die Attribute nicht verändert und als const-Methode darf sie auch auf const-Objekten ausgeführt werden

# Was ist im Zusammenhang der const-Correctness der Unterschied zwischen einer Methode und einer freien Funktion?
Bei einer Member-Methode bezieht sich "const" auf das Objekt, bei dem die Methode aufgerufen wird. Mit "const" darf sie
keine Attribute ändern.
Bei einer freien Methode bezieht sich "const" auf die Objekte in Parameter. Diese lassen sich innerhalb der Methode nicht verändern.
const-Methoden dürfen aufgerufen werden.