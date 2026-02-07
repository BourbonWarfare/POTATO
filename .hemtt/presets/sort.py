import re

# Read the HTML file
with open(r'.hemtt\presets\bw.html', 'r', encoding='utf-8') as f:
    html_content = f.read()

# Extract all mod rows (tr elements with data-type="ModContainer")
mod_rows = re.findall(r'<tr data-type="ModContainer">.*?</tr>', html_content, re.DOTALL)

# Extract URL from each row
rows_with_urls = []
for row in mod_rows:
    url_match = re.search(r'href="(https://steamcommunity\.com/sharedfiles/filedetails/\?id=\d+)"', row)
    if url_match:
        url = url_match.group(1)
        rows_with_urls.append((url, row))

# removed cba/ace/potato/acre links
rows_with_urls = [
    (url, row) for url, row in rows_with_urls
    if not (url.endswith('2987557792') or url.endswith('450814997') or url.endswith('2987524550') or url.endswith('751965892'))
]
# Sort by URL
rows_with_urls.sort(key=lambda x: x[0])

# Rebuild HTML with sorted rows
sorted_rows = '\n        '.join([row for url, row in rows_with_urls])
new_html = re.sub(
    r'(<div class="mod-list">\s*<table>\s*)<tr data-type="ModContainer">.*?</tr>(\s*</table>)',
    r'\1' + sorted_rows + r'\2',
    html_content,
    flags=re.DOTALL
)

# Write back to file
with open(r'.hemtt\presets\bw.html', 'w', encoding='utf-8') as f:
    f.write(new_html)

print(f"Sorted {len(rows_with_urls)} mods by URL")
