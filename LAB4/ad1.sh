filename=$1
permissions=$(stat -c '%A' "$filename")
owner_perms=${permissions:1:3}
group_perms=${permissions:4:3}
others_perms=${permissions:7:3}
echo "Permissions for file '$filename':"
echo "Owner:   $owner_perms"
echo "Group:   $group_perms"
echo "Others:  $others_perms"