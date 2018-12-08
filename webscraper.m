html = string(webread('https://liben002.github.io/delete.html'));
pattern1 = '<Data Name="SourceAddress">';
pattern2 = '</Data>';
srcaddress = extractBetween(html, pattern1, pattern2);
pattern1 = '<Data Name="DestAddress">';
dstaddress = extractBetween(html, pattern1, pattern2);
dat(1) = struct('src', srcaddress(1), 'dst', dstaddress(1));
for i = 2:length(dstaddress)
    dat(i).src = srcaddress(i);
    dat(i).dst = dstaddress(i);
end
file = fopen("ips.dat", "w");
for i = 1:length(dat)
    fprintf(file, "%s %s\n", dat(i).src, dat(i).dst);
end
fclose(file);

