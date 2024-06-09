echo $1, $2

for i in {1..10}
do
    ((x = $1 + $i))
    ((y = $2 + $i))
    bfr="ABC"$x
    aft="ABC"$y

    cp -r $bfr $aft
done

