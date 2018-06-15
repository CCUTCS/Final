import os
import re

its = os.listdir('./')
for it in its:
  if re.search('Q\d+', it):
    num = int(re.findall('\d+', it)[0])
    os.rename(it, 'Q{0}'.format(str(num).zfill(2)))

