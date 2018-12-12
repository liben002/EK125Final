            country_dataFID = fopen("country_data.dat",'r');
            aline = fgetl(country_dataFID);
            value = 'Top Three Countries That Are Targeted';
            count = 1;
            while aline ~= -1
                top3data(count) = string(aline);
                value = strcat(value,sprintf('\n%s',aline));
                app.LocationsTextArea.Value = value;
                aline = fgetl(country_dataFID);
                count = count + 1;
            end
            for i = 1:length(top3data)
                vals = strsplit(top3data(i));
                xval(i) = vals(1);
                yval(i) = str2double(vals(2));
            end