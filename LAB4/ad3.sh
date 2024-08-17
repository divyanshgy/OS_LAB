filename=$1
start_line=$2
end_line=$3
if [ "$start_line" -gt "$end_line" ]; then
    echo "Error: Start line cannot be greater than end line."
    exit 1
fi
sed -n "${start_line},${end_line}p" "$filename" 