echo $.$.

echo "$.$."

echo '"$.$."''

echo "'$.$.'"

echo $?+$?

echo $? + $?

echo "$?+$?"

echo "$? + $?"

echo '$?+$?'

echo '$? + $?'

echo $$

echo "$$"

echo '$$'

echo $$?

echo "$$?"

echo '$$?'

echo $$??

echo "$$??"

echo '$$??'

echo $123abc

echo $abc123abc

echo $a1bc

echo $PWD?

echo $PWD??

echo ?$PWD??

echo "$PWD?"

echo "$PWD??"

echo "?$PWD??"

echo "??$PWD."

echo $PWD.

echo .$PWD.

echo "$PWD."

echo ".$PWD."

echo "..$PWD.."

echo $PWD$.

echo "$PWD$."

echo "$..$PWD$.."

echo $PWD . $PWD

echo "$PWD . $PWD"

echo ".$PWD		.		$PWD."

<<eof cat
$?
$??
$.$<$PWD
"$?"
"$??"
"$<$."
"$."
".$#$PWD"
"$???.$'PWD'"'$HOME'$EMPTY
'EOF'$PWD'$HOME'$?.$?'
eof

<<eof'end' cat
$?
$??
$.$<$PWD
"$?"
"$??"
"$<$."
"$."
".$#$PWD"
"$???.$'PWD'"'$HOME'$EMPTY
'										'
eofend


# ambiguous redirect

< $TSISY cat

export var="abc def"
<var cat > out

< minishell.h cat -e > $PATH

< minishell.h cat -e > $TSISY

