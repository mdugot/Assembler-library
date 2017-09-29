if [ $# -ne 0 ]
then
	echo "usage : ./diff.sh"
	exit
fi
diff <( ./ft_checker ) <( ./c_checker )

