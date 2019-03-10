import xml.etree.ElementTree as ET
tree = ET.parse('oj-template.xml')
root = tree.getroot()

print(root[1][0].tag)
print(root[1][3].tag)
print(root[1][4].tag)

import docx
doc = docx.Document('/home/tjy/Downloads/DKUOJ-UserID-Title.docx')

section_content = {"Title":"",
"Level":"",
"Description":"",
"Input":"",
"Output":"",
"Sample Input":"",
"Sample Output":"",
"Test Input":"",
"Test Output":"",
"Hint":"",
"Source/Category":""
}

for i in range(len(doc.paragraphs)):
    if doc.paragraphs[i].text in section_content.keys():
        t = doc.paragraphs[i].text
    else:
        section_content[t] += doc.paragraphs[i].text

#print(section_content)

