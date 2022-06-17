mkdir -p result
./conversion '0' > 'result/0'
./conversion 'nan' > 'result/nan'
./conversion '42.0f' > 'result/42.0f'
./conversion 'inf' > 'result/inf'
./conversion 'n' > 'result/n'
./conversion 'nanf' > 'result/nanf'
./conversion '42' > 'result/42'
./conversion '42.042' > 'result/42.042'
./conversion '4.2f' > 'result/4.2f'
diff answer result