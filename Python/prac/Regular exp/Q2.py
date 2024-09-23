import re

txt="hi my name is sara and my # is 234-89808-0999"
s="sara"
a="is"
re.search("\d\d\d-\d\d\d\d\d-\d\d\d\d",txt)
re.search(r"\d{3}-\d{5}-\d{4}",txt)
