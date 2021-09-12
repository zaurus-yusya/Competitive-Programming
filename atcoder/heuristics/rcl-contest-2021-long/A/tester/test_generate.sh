for i in {1..50}; do
    python3 generator.py $i > in/in$i.txt;
done