import re

txt="the cat in the pink hat "
re.findall(r".at",txt)
re.findall(r"^\W",txt)#checks if txt start with an alpha bet
re.findall(r"\W$",txt)#checks if txt ends with an alpha bet
re.findall(r"[^i]+",txt)#excludes
