i=1
for file in "$@"
do
	printf "%d: %s\n" $i $file&
	echo "${file}" > "${file}".generic.h;
	i=$((i + 1));
done
wait
echo "All Done!"